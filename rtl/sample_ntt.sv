// -----------------------------------------------------------------------------
// Author      : Salwan Aldhahab
// Module      : sample_ntt
// Standard    : FIPS 203 ML-KEM — Algorithm 7 (SampleNTT)
//
// Description :
//   Rejection sampler that converts an infinite SHAKE-128 byte stream into
//   exactly 256 NTT-domain coefficients in Z_q  (q = 3329).
//
//   Every 3 input bytes (b0, b1, b2) produce two 12-bit candidates:
//       d1 = b0      + 256 * (b1 mod 16)       i.e.  b0 + 256*(b1[3:0])
//       d2 = (b1/16) +  16 * b2                 i.e.  (b1>>4) + 16*b2
//   A candidate is accepted only when it is < q.  Rejected candidates are
//   simply discarded and the next 3-byte triple is consumed.
//
//   Accepted coefficients are packed four-at-a-time into a 48-bit output
//   beat  {c3[11:0], c2[11:0], c1[11:0], c0[11:0]}  and emitted over an
//   AXI4-Stream source interface (64 beats total for 256 coefficients).
//
// Micro-architecture:
//
//   ┌───────────┐   AXI-S sink   ┌────────────┐  3-byte   ┌──────────┐
//   │  Keccak   │──────────────▸ │ Byte FIFO  │─────────▸ │Rejection │
//   │  (SHAKE)  │  256b beats    │ 64 entries │  triples  │  Sampler │
//   └───────────┘                └────────────┘           └────┬─────┘
//                                                              │ 0-2 coeffs/cycle
//                                                         ┌────▼─────┐
//                                     AXI-S source        │ 4-coeff  │
//                               ◂─────────────────────────│ Packer + │
//                                 48-bit beats            │ Skid Buf │
//                                                         └──────────┘
//
//   • Byte FIFO       – 64-byte circular buffer absorbing AXI beats.
//   • Rejection logic – purely combinational; peeks 3 bytes, produces d1/d2.
//   • 4-coeff packer  – collects accepted 12-bit values; when four are ready
//                        they are concatenated into a 48-bit word.
//   • Skid buffer      – 2-entry output queue so the packer never stalls on
//                        downstream backpressure for a single cycle.
//
// Handshake notes:
//   • t_ready_o is asserted only while the FIFO can accept a full beat.
//   • t_last_o marks the final (64th) output beat carrying coefficients 253-256.
//   • done pulses high for one cycle after all 256 coefficients have been
//     emitted and the output queue is fully drained.
// -----------------------------------------------------------------------------

module sample_ntt #(
    parameter int DWIDTH     = 256,          // Input AXI beat width (bits)
    parameter int KEEP_WIDTH = DWIDTH / 8    // Byte-enable width
) (
    input  wire                      clk,
    input  wire                      rst,

    // Control
    input  wire                      start,   // Pulse to begin sampling
    output logic                     done,    // Pulse when 256 coefficients delivered

    // AXI4-Stream Sink (from Keccak / SHAKE source)
    input  wire  [DWIDTH-1:0]        t_data_i,
    input  wire                      t_valid_i,
    input  wire                      t_last_i,
    input  wire  [KEEP_WIDTH-1:0]    t_keep_i,
    output logic                     t_ready_o,

    // AXI4-Stream Source (to downstream consumer)
    output logic [47:0]              t_data_o,  // 4 × 12-bit packed coefficients
    output logic                     t_valid_o,
    output logic                     t_last_o,
    output logic [5:0]               t_keep_o,  // 6 valid bytes per beat
    input  wire                      t_ready_i
);

    // =========================================================================
    // 1. PARAMETERS & TYPES
    // =========================================================================

    localparam int Q              = 3329;  // Kyber modulus
    localparam int TARGET_COEFFS  = 256;   // Polynomial degree
    localparam int FIFO_DEPTH     = 64;    // Byte FIFO depth

    typedef enum logic [1:0] {
        S_IDLE,
        S_RUN,
        S_DONE
    } state_t;

    // One entry in the 2-deep output skid buffer.
    typedef struct packed {
        logic [47:0] data;
        logic        last;
    } beat_t;

    // =========================================================================
    // 2. REGISTERS
    // =========================================================================

    // -- FSM --
    state_t state;

    // -- Byte FIFO --
    logic [7:0]  fifo [FIFO_DEPTH];
    logic [6:0]  fifo_count;    // 0 .. 64
    logic [5:0]  fifo_wr_ptr;
    logic [5:0]  fifo_rd_ptr;

    // -- Coefficient aggregator (collects 4 before emitting a beat) --
    logic [11:0] agg [4];
    logic [2:0]  agg_count;     // 0 .. 4

    // -- 2-entry output skid buffer --
    beat_t       oq      [2];
    logic        oq_valid[2];

    // -- Global progress --
    logic [8:0]  coeff_count;   // 0 .. 256  (9 bits)

    // =========================================================================
    // 3. COMBINATIONAL: AXI Source Output
    // =========================================================================

    always_comb begin
        t_data_o  = oq[0].data;
        t_valid_o = oq_valid[0];
        t_last_o  = oq_valid[0] & oq[0].last;
        t_keep_o  = oq_valid[0] ? 6'h3F : 6'h00;
    end

    // =========================================================================
    // 4. COMBINATIONAL: AXI Sink Ready
    // =========================================================================
    //    Accept a new beat only while running and the FIFO has room for the
    //    incoming valid bytes (avoids overflow for partial-keep beats).

    function automatic logic [5:0] count_keep_bytes(input logic [KEEP_WIDTH-1:0] k);
        logic [5:0] n;
        n = 6'd0;
        for (int i = 0; i < KEEP_WIDTH; i++)
            if (k[i]) n = n + 6'd1;
        return n;
    endfunction

    logic [6:0] sink_bytes;
    always_comb begin
        sink_bytes = t_valid_i ? count_keep_bytes(t_keep_i) : 7'd1;
        t_ready_o  = (state == S_RUN) && ((7'(FIFO_DEPTH) - fifo_count) >= sink_bytes);
    end

    // =========================================================================
    // 5. COMBINATIONAL: Rejection Sampling (peek 3 bytes)
    // =========================================================================
    //    Reads are direct FIFO indexing — no function wrapper needed.
    //    d1 and d2 are pure concatenations (no adders required).

    logic        have_triple;
    logic [7:0]  b0, b1, b2;
    logic [11:0] d1, d2;
    logic        d1_valid, d2_valid;

    always_comb begin
        have_triple = (fifo_count >= 7'd3);

        b0 = fifo[fifo_rd_ptr];
        b1 = fifo[fifo_rd_ptr + 6'd1];
        b2 = fifo[fifo_rd_ptr + 6'd2];

        d1 = {b1[3:0], b0};        // b0 + 256 * (b1 mod 16)
        d2 = {b2, b1[7:4]};        // (b1 / 16) + 16 * b2

        d1_valid = have_triple && (d1 < 12'(Q));
        d2_valid = have_triple && (d2 < 12'(Q));
    end

    // =========================================================================
    // 6. COMBINATIONAL: Flow-control gating for chunk processing
    // =========================================================================
    //    We only consume a 3-byte triple when the output path can absorb
    //    every coefficient that triple might yield (0, 1, or 2).

    logic [1:0] coeffs_from_triple;    // How many coefficients this triple yields
    logic       triple_fills_packer;   // True if processing this triple completes a 4-coeff beat
    logic [1:0] oq_free_slots;         // Empty slots in the output skid buffer

    always_comb begin
        // Count valid candidates, respecting the 256 limit.
        coeffs_from_triple = 2'd0;
        if (d1_valid && (coeff_count < TARGET_COEFFS))
            coeffs_from_triple = coeffs_from_triple + 2'd1;
        if (d2_valid && ((coeff_count + (d1_valid ? 9'd1 : 9'd0)) < TARGET_COEFFS))
            coeffs_from_triple = coeffs_from_triple + 2'd1;

        // Will the aggregator reach 4 and emit a packed beat?
        triple_fills_packer = (coeffs_from_triple != 2'd0)
                            && ((agg_count + {1'b0, coeffs_from_triple}) >= 3'd4);

        // Free output slots.
        oq_free_slots = 2'd2 - {1'b0, oq_valid[0]} - {1'b0, oq_valid[1]};
    end

    // =========================================================================
    // 7. COMBINATIONAL: Next-State Logic
    // =========================================================================
    //    Standard two-process style: this always_comb computes every next-state
    //    value; the always_ff in Section 8 simply latches them.  No 'automatic'
    //    variables inside always_ff — portable across all synthesis tools.

    // -- FIFO write ports (one per input byte lane) --
    logic        fifo_wr_en   [KEEP_WIDTH];
    logic [5:0]  fifo_wr_addr [KEEP_WIDTH];

    // -- Next-state wires --
    state_t      state_nxt;
    logic        done_nxt;
    logic [6:0]  fifo_count_nxt;
    logic [5:0]  fifo_wr_ptr_nxt;
    logic [5:0]  fifo_rd_ptr_nxt;
    logic [11:0] agg_nxt      [4];
    logic [2:0]  agg_count_nxt;
    beat_t       oq_nxt       [2];
    logic        oq_valid_nxt [2];
    logic [8:0]  coeff_count_nxt;

    // -- Working signals for Step C --
    logic [1:0]  oq_free_after_deq;
    logic        can_process;

    always_comb begin

        // -- Defaults: hold current value --
        state_nxt        = state;
        done_nxt         = 1'b0;
        fifo_count_nxt   = fifo_count;
        fifo_wr_ptr_nxt  = fifo_wr_ptr;
        fifo_rd_ptr_nxt  = fifo_rd_ptr;
        agg_nxt[0]       = agg[0];
        agg_nxt[1]       = agg[1];
        agg_nxt[2]       = agg[2];
        agg_nxt[3]       = agg[3];
        agg_count_nxt    = agg_count;
        oq_nxt[0]        = oq[0];
        oq_nxt[1]        = oq[1];
        oq_valid_nxt[0]  = oq_valid[0];
        oq_valid_nxt[1]  = oq_valid[1];
        coeff_count_nxt  = coeff_count;

        for (int i = 0; i < KEEP_WIDTH; i++) begin
            fifo_wr_en[i]   = 1'b0;
            fifo_wr_addr[i] = 6'd0;
        end

        oq_free_after_deq = 2'd0;
        can_process       = 1'b0;

        case (state)

            // ---------------------------------------------------------
            // IDLE — wait for start pulse, clear datapath.
            // ---------------------------------------------------------
            S_IDLE: begin
                if (start) begin
                    state_nxt        = S_RUN;
                    fifo_count_nxt   = 7'd0;
                    fifo_wr_ptr_nxt  = 6'd0;
                    fifo_rd_ptr_nxt  = 6'd0;
                    agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                    agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                    agg_count_nxt    = 3'd0;
                    oq_nxt[0]  = '0;     oq_nxt[1]  = '0;
                    oq_valid_nxt[0]  = 1'b0;
                    oq_valid_nxt[1]  = 1'b0;
                    coeff_count_nxt  = 9'd0;
                end
            end

            // ---------------------------------------------------------
            // RUN — pipeline: dequeue → enqueue → sample → completion
            // ---------------------------------------------------------
            S_RUN: begin

                // ── Step A: Output dequeue ──────────────────────────
                //    If the downstream consumer accepts oq[0], shift
                //    oq[1] forward.
                if (oq_valid_nxt[0] && t_ready_i) begin
                    oq_nxt[0]       = oq_nxt[1];
                    oq_valid_nxt[0] = oq_valid_nxt[1];
                    oq_valid_nxt[1] = 1'b0;
                end

                // ── Step B: FIFO enqueue from AXI sink ─────────────
                //    Compute per-lane write-enable & address; the
                //    actual memory write happens in Section 8.
                if (t_valid_i && t_ready_o) begin
                    for (int i = 0; i < KEEP_WIDTH; i++) begin
                        if (t_keep_i[i] && (fifo_count_nxt < 7'(FIFO_DEPTH))) begin
                            fifo_wr_en[i]   = 1'b1;
                            fifo_wr_addr[i] = fifo_wr_ptr_nxt;
                            fifo_wr_ptr_nxt = fifo_wr_ptr_nxt + 6'd1;
                            fifo_count_nxt  = fifo_count_nxt  + 7'd1;
                        end
                    end
                end

                // ── Step C: Rejection sampling & packing ───────────
                oq_free_after_deq = 2'd2 - {1'b0, oq_valid_nxt[0]}
                                         - {1'b0, oq_valid_nxt[1]};

                can_process = have_triple
                            && (oq_free_after_deq >= (triple_fills_packer ? 2'd1 : 2'd0))
                            && (coeff_count_nxt < 9'(TARGET_COEFFS));

                if (can_process) begin
                    // Pop 3 bytes from the FIFO.
                    fifo_rd_ptr_nxt = fifo_rd_ptr_nxt + 6'd3;
                    fifo_count_nxt  = fifo_count_nxt  - 7'd3;

                    // -- Try d1 --
                    if (d1_valid && (coeff_count_nxt < 9'(TARGET_COEFFS))) begin
                        agg_nxt[agg_count_nxt] = d1;
                        agg_count_nxt   = agg_count_nxt + 3'd1;
                        coeff_count_nxt = coeff_count_nxt + 9'd1;

                        if (agg_count_nxt == 3'd4) begin
                            if (!oq_valid_nxt[0]) begin
                                oq_nxt[0].data   = {agg_nxt[3], agg_nxt[2],
                                                     agg_nxt[1], agg_nxt[0]};
                                oq_nxt[0].last   = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[0]  = 1'b1;
                            end else begin
                                oq_nxt[1].data   = {agg_nxt[3], agg_nxt[2],
                                                     agg_nxt[1], agg_nxt[0]};
                                oq_nxt[1].last   = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[1]  = 1'b1;
                            end
                            agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                            agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                            agg_count_nxt = 3'd0;
                        end
                    end

                    // -- Try d2 --
                    if (d2_valid && (coeff_count_nxt < 9'(TARGET_COEFFS))) begin
                        agg_nxt[agg_count_nxt] = d2;
                        agg_count_nxt   = agg_count_nxt + 3'd1;
                        coeff_count_nxt = coeff_count_nxt + 9'd1;

                        if (agg_count_nxt == 3'd4) begin
                            if (!oq_valid_nxt[0]) begin
                                oq_nxt[0].data   = {agg_nxt[3], agg_nxt[2],
                                                     agg_nxt[1], agg_nxt[0]};
                                oq_nxt[0].last   = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[0]  = 1'b1;
                            end else begin
                                oq_nxt[1].data   = {agg_nxt[3], agg_nxt[2],
                                                     agg_nxt[1], agg_nxt[0]};
                                oq_nxt[1].last   = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[1]  = 1'b1;
                            end
                            agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                            agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                            agg_count_nxt = 3'd0;
                        end
                    end
                end

                // ── Step D: Completion check ───────────────────────
                if ((coeff_count_nxt >= 9'(TARGET_COEFFS))
                    && !oq_valid_nxt[0] && !oq_valid_nxt[1]
                    && (agg_count_nxt == 3'd0)) begin
                    state_nxt = S_DONE;
                end

            end // S_RUN

            // ---------------------------------------------------------
            // DONE — one-cycle pulse, then back to idle.
            // ---------------------------------------------------------
            S_DONE: begin
                done_nxt  = 1'b1;
                state_nxt = S_IDLE;
            end

            default: state_nxt = S_IDLE;
        endcase
    end

    // =========================================================================
    // 8. SEQUENTIAL: Register Update
    // =========================================================================
    //    Pure reg <= nxt assignments.  FIFO memory writes use precomputed
    //    enables and addresses from Section 7 — no blocking/non-blocking mix.

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= S_IDLE;
            done        <= 1'b0;
            fifo_count  <= 7'd0;
            fifo_wr_ptr <= 6'd0;
            fifo_rd_ptr <= 6'd0;
            agg[0]      <= 12'd0;  agg[1] <= 12'd0;
            agg[2]      <= 12'd0;  agg[3] <= 12'd0;
            agg_count   <= 3'd0;
            oq[0]       <= '0;     oq[1]  <= '0;
            oq_valid[0] <= 1'b0;   oq_valid[1] <= 1'b0;
            coeff_count <= 9'd0;
        end else begin
            state       <= state_nxt;
            done        <= done_nxt;
            fifo_count  <= fifo_count_nxt;
            fifo_wr_ptr <= fifo_wr_ptr_nxt;
            fifo_rd_ptr <= fifo_rd_ptr_nxt;
            agg[0]      <= agg_nxt[0];
            agg[1]      <= agg_nxt[1];
            agg[2]      <= agg_nxt[2];
            agg[3]      <= agg_nxt[3];
            agg_count   <= agg_count_nxt;
            oq[0]       <= oq_nxt[0];
            oq[1]       <= oq_nxt[1];
            oq_valid[0] <= oq_valid_nxt[0];
            oq_valid[1] <= oq_valid_nxt[1];
            coeff_count <= coeff_count_nxt;

            // FIFO memory writes (addresses/enables from Section 7).
            for (int i = 0; i < KEEP_WIDTH; i++) begin
                if (fifo_wr_en[i])
                    fifo[fifo_wr_addr[i]] <= t_data_i[8*i +: 8];
            end
        end
    end

    // =========================================================================
    // 9. ASSERTIONS (simulation only)
    // =========================================================================
    // synthesis translate_off

    // FIFO must never overflow.
    assert property (@(posedge clk) disable iff (rst) fifo_count <= FIFO_DEPTH)
        else $fatal(1, "FIFO count overflow: %0d", fifo_count);

    // Coefficient counter must never exceed target.
    assert property (@(posedge clk) disable iff (rst) coeff_count <= TARGET_COEFFS)
        else $fatal(1, "coeff_count overflow: %0d", coeff_count);

    // AXI sink: data/keep/last stable while back-pressured.
    assert property (@(posedge clk) disable iff (rst)
        (t_valid_i && !t_ready_o) |-> ##1 $stable(t_data_i) && $stable(t_keep_i) && $stable(t_last_i))
        else $error("AXI sink: signals changed during backpressure");

    // AXI source: output stable while back-pressured.
    assert property (@(posedge clk) disable iff (rst)
        (t_valid_o && !t_ready_i) |-> ##1 $stable(t_data_o) && $stable(t_keep_o) && $stable(t_last_o))
        else $error("AXI source: signals changed during backpressure");

    // synthesis translate_on

endmodule
