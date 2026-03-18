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
// Micro-architecture (revised):
//
//   ┌───────────┐   AXI-S sink   ┌────────────┐  256-bit words  ┌──────────┐
//   │  Keccak   │──────────────▸ │ Wide FIFO  │───────────────▸ │ Gearbox  │
//   │  (SHAKE)  │  256b beats    │ 4 entries  │  1 read/cycle   │ 6B/cycle │
//   └───────────┘  1 write/beat  └────────────┘                 └────┬─────┘
//                                                                     │ 6 bytes (2 triples)
//                                                              ┌──────▼──────┐
//                                                              │  Parallel   │
//                                                              │  Samplers   │
//                                                              │  (Stage 0)  │
//                                                              └──────┬──────┘
//                                                                     │ pipeline register
//                                                              ┌──────▼──────┐
//                                                              │  Stage 1    │
//                                                              │  (Reg)      │
//                                                              └──────┬──────┘
//                                                                     │ 0-4 coeffs/cycle
//                                                              ┌──────▼──────┐
//                                      AXI-S source           │ 4-coeff     │
//                                ◂─────────────────────────── │ Packer +    │
//                                  48-bit beats               │ Skid Buf    │
//                                                              └─────────────┘
//
//   • Wide FIFO    – 4 × 256-bit word entries.  Each AXI beat is stored with a
//                    single DWIDTH-bit write (one write port, BRAM-friendly).
//   • Gearbox      – double-buffer (word0 + word1).  Reads exactly 6 bytes per
//                    cycle via a variable part-select shift-MUX; handles cross-
//                    word-boundary spans transparently.
//   • Stage 0      – two triples evaluated in parallel (purely combinational).
//   • Stage 1      – pipeline register latching Stage 0 comparator outputs,
//                    breaking the deep combinational path before the aggregator.
//   • 4-coeff packer – receives 0-4 accepted 12-bit values per cycle from
//                    Stage 1; emits a packed 48-bit beat whenever 4 accumulate.
//   • Skid buffer  – 2-entry output queue absorbs downstream back-pressure.
//
// Changes from v1:
//   1. Wide FIFO replaces the byte-addressable array: each AXI beat writes a
//      single 256-bit word (eliminates the implicit 32-write-port RAM that
//      prevented BRAM inference and generated a large LUT crossbar).
//   2. A gearbox double-buffer reads 6 bytes/cycle using a variable part-select
//      (synthesises as a shift-MUX, not multi-ported RAM).
//   3. Two triples are processed in parallel; comparator outputs are registered
//      (Stage 0 → Stage 1 pipeline) to improve Fmax.
//   4. t_ready_o is now registered: decouples upstream back-pressure from the
//      combinational path driven by t_ready_i.
//
// Handshake notes:
//   • t_ready_o is registered — one-cycle latency between an internal count
//     change and the upstream source seeing back-pressure.
//   • t_last_o marks the final (64th) output beat (coefficients 253-256).
//   • done pulses high for one cycle after all 256 coefficients are delivered,
//     the output queue is drained, and the pipeline is empty.
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

    localparam int Q             = 3329;  // Kyber modulus
    localparam int TARGET_COEFFS = 256;   // Polynomial degree
    localparam int WFIFO_DEPTH   = 4;     // Wide FIFO depth (4 × 256-bit words)

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

    // -- Wide word FIFO (single write port per AXI beat) --
    // Each AXI beat is written as one 256-bit word — exactly one write port,
    // which allows BRAM inference and avoids a 32-entry LUT crossbar.
    logic [DWIDTH-1:0]  wfifo [WFIFO_DEPTH];
    logic [1:0]         wfifo_wr_ptr;
    logic [1:0]         wfifo_rd_ptr;
    logic [2:0]         wfifo_count;   // 0 .. 4

    // -- Gearbox double-buffer --
    // Holds at most two 256-bit words so that a 6-byte read can span a word
    // boundary without stalling.  A variable part-select extracts the window.
    logic [DWIDTH-1:0]  gbx_word0;     // Word being consumed
    logic [DWIDTH-1:0]  gbx_word1;     // Pre-fetched next word
    logic               gbx_w0v;       // word0 is valid
    logic               gbx_w1v;       // word1 is valid
    logic [4:0]         gbx_boff;      // Byte offset within word0 (0 .. 31)

    // -- Pipeline Stage 1 (registered comparator outputs) --
    // Latches the 4 candidate values and their validity flags from Stage 0.
    // This register breaks the deep combinational path through the comparators.
    logic               s1_valid;
    logic [11:0]        s1_d1_a, s1_d2_a, s1_d1_b, s1_d2_b;
    logic               s1_d1_av, s1_d2_av, s1_d1_bv, s1_d2_bv;

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
    // 4. COMBINATIONAL: Gearbox 6-byte read window
    // =========================================================================
    //    The double-buffer is viewed as a contiguous 512-bit word:
    //      {gbx_word1, gbx_word0}.
    //    A variable part-select (fixed width, variable start) extracts the
    //    current 6-byte window.  This synthesises as a shift-MUX tree, NOT as
    //    a multi-ported RAM — no BRAM inference issues.
    //    The read is valid only when word0 is loaded AND the 6 bytes either
    //    lie entirely in word0 (boff + 6 <= 32) or word1 is also loaded.

    logic [8:0]  gbx_bit_ptr;   // gbx_boff × 8 — start bit of the window
    logic [47:0] six_bytes;     // 6-byte window extracted from the double-buffer
    logic        have_6bytes;   // Gearbox can serve a complete 6-byte window

    always_comb begin
        gbx_bit_ptr = {1'b0, gbx_boff, 3'b000};             // gbx_boff * 8 (9 bits)
        six_bytes   = {gbx_word1, gbx_word0}[gbx_bit_ptr +: 48];
        have_6bytes = gbx_w0v
                    && (({1'b0, gbx_boff} + 6'd6) <= 6'd32 || gbx_w1v);
    end

    // =========================================================================
    // 5. COMBINATIONAL: Stage 0 — two triples from the 6-byte window
    // =========================================================================
    //    Decode the two triples (A = bytes 0-2, B = bytes 3-5) and form the
    //    four 12-bit candidates.  Comparisons are registered in Stage 1.

    logic [7:0]  b0_a, b1_a, b2_a;
    logic [7:0]  b0_b, b1_b, b2_b;
    logic [11:0] d1_a, d2_a, d1_b, d2_b;

    always_comb begin
        b0_a = six_bytes[ 7: 0];
        b1_a = six_bytes[15: 8];
        b2_a = six_bytes[23:16];
        b0_b = six_bytes[31:24];
        b1_b = six_bytes[39:32];
        b2_b = six_bytes[47:40];

        d1_a = {b1_a[3:0], b0_a};        // b0 + 256*(b1 & 0xF)
        d2_a = {b2_a,      b1_a[7:4]};   // (b1 >> 4) + 16*b2
        d1_b = {b1_b[3:0], b0_b};
        d2_b = {b2_b,      b1_b[7:4]};
    end

    // =========================================================================
    // 6. COMBINATIONAL: Flow-control — stall / advance signals
    // =========================================================================
    //    Computed once from registered state, used throughout Section 7.

    logic [2:0]  s1_accepted;    // Number of valid candidates in Stage 1
    logic        s1_will_emit;   // Stage 1 processing will complete a beat
    logic        oq_full;        // Both output-queue slots occupied
    logic        s1_stall;       // Stage 1 cannot drain this cycle
    logic        pipe_advance;   // Pipeline is free to advance

    always_comb begin
        s1_accepted  = {2'b0, s1_d1_av} + {2'b0, s1_d2_av}
                     + {2'b0, s1_d1_bv} + {2'b0, s1_d2_bv};

        s1_will_emit = s1_valid
                     && (({1'b0, agg_count} + {1'b0, s1_accepted}) >= 4'd4);

        oq_full      = oq_valid[0] && oq_valid[1];

        // Stall when Stage 1 would need to enqueue a new beat but the output
        // queue is full and the downstream consumer is not accepting this cycle.
        s1_stall     = s1_will_emit && oq_full && !t_ready_i;

        pipe_advance = !s1_stall;
    end

    // =========================================================================
    // 7. COMBINATIONAL: Next-State Logic
    // =========================================================================
    //    Standard two-process style: this always_comb computes every _nxt
    //    signal; the always_ff in Section 8 latches them.
    //
    //    Processing order within S_RUN:
    //      A  Output dequeue  (shift oq[1] → oq[0] if downstream accepts)
    //      B  AXI beat → wide FIFO  (single 256-bit write; updates wfifo_count)
    //      D  Stage 1 → Aggregator  (pack up to 4 candidates; emit beat if ≥4)
    //      E  Stage 0 → Stage 1     (gearbox advance + pipeline register latch)
    //      C  Gearbox refill        (load word0 or word1 from wfifo after E)
    //      F  Completion check      (transition to S_DONE when pipeline drained)

    // -- Next-state wires --
    state_t      state_nxt;
    logic        done_nxt;
    logic [1:0]  wfifo_wr_ptr_nxt;
    logic [1:0]  wfifo_rd_ptr_nxt;
    logic [2:0]  wfifo_count_nxt;
    logic [DWIDTH-1:0] gbx_word0_nxt, gbx_word1_nxt;
    logic        gbx_w0v_nxt, gbx_w1v_nxt;
    logic [4:0]  gbx_boff_nxt;
    logic        s1_valid_nxt;
    logic [11:0] s1_d1_a_nxt, s1_d2_a_nxt, s1_d1_b_nxt, s1_d2_b_nxt;
    logic        s1_d1_av_nxt, s1_d2_av_nxt, s1_d1_bv_nxt, s1_d2_bv_nxt;
    logic [11:0] agg_nxt [4];
    logic [2:0]  agg_count_nxt;
    beat_t       oq_nxt  [2];
    logic        oq_valid_nxt [2];
    logic [8:0]  coeff_count_nxt;

    // -- Working signals (combinational, no register) --
    logic [5:0]  boff_plus6;   // gbx_boff + 6, 6-bit to detect wraparound at 32
    logic [8:0]  cnt_base;     // coeff_count after Stage-1 contribution (for Stage-0 validity)
    logic        s0_d1_av, s0_d2_av, s0_d1_bv, s0_d2_bv;  // Stage-0 candidate validity

    always_comb begin

        // ── Defaults: hold registered values ─────────────────────────────
        state_nxt        = state;
        done_nxt         = 1'b0;
        wfifo_wr_ptr_nxt = wfifo_wr_ptr;
        wfifo_rd_ptr_nxt = wfifo_rd_ptr;
        wfifo_count_nxt  = wfifo_count;
        gbx_word0_nxt    = gbx_word0;
        gbx_word1_nxt    = gbx_word1;
        gbx_w0v_nxt      = gbx_w0v;
        gbx_w1v_nxt      = gbx_w1v;
        gbx_boff_nxt     = gbx_boff;
        s1_valid_nxt     = s1_valid;
        s1_d1_a_nxt      = s1_d1_a;   s1_d2_a_nxt  = s1_d2_a;
        s1_d1_b_nxt      = s1_d1_b;   s1_d2_b_nxt  = s1_d2_b;
        s1_d1_av_nxt     = s1_d1_av;  s1_d2_av_nxt = s1_d2_av;
        s1_d1_bv_nxt     = s1_d1_bv;  s1_d2_bv_nxt = s1_d2_bv;
        agg_nxt[0]       = agg[0];    agg_nxt[1]   = agg[1];
        agg_nxt[2]       = agg[2];    agg_nxt[3]   = agg[3];
        agg_count_nxt    = agg_count;
        oq_nxt[0]        = oq[0];     oq_nxt[1]    = oq[1];
        oq_valid_nxt[0]  = oq_valid[0];
        oq_valid_nxt[1]  = oq_valid[1];
        coeff_count_nxt  = coeff_count;

        boff_plus6 = 6'd0;
        cnt_base   = 9'd0;
        s0_d1_av   = 1'b0;  s0_d2_av = 1'b0;
        s0_d1_bv   = 1'b0;  s0_d2_bv = 1'b0;

        case (state)

            // -----------------------------------------------------------------
            // IDLE — wait for start pulse, clear datapath on start.
            // -----------------------------------------------------------------
            S_IDLE: begin
                if (start) begin
                    state_nxt        = S_RUN;
                    wfifo_wr_ptr_nxt = 2'd0;
                    wfifo_rd_ptr_nxt = 2'd0;
                    wfifo_count_nxt  = 3'd0;
                    gbx_w0v_nxt      = 1'b0;
                    gbx_w1v_nxt      = 1'b0;
                    gbx_boff_nxt     = 5'd0;
                    s1_valid_nxt     = 1'b0;
                    agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                    agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                    agg_count_nxt    = 3'd0;
                    oq_nxt[0]        = '0;  oq_nxt[1] = '0;
                    oq_valid_nxt[0]  = 1'b0;
                    oq_valid_nxt[1]  = 1'b0;
                    coeff_count_nxt  = 9'd0;
                end
            end

            // -----------------------------------------------------------------
            // RUN — pipeline: dequeue → write → packer → sample → refill
            // -----------------------------------------------------------------
            S_RUN: begin

                // ── Step A: Output-queue dequeue ─────────────────────────
                if (oq_valid_nxt[0] && t_ready_i) begin
                    oq_nxt[0]       = oq_nxt[1];
                    oq_valid_nxt[0] = oq_valid_nxt[1];
                    oq_valid_nxt[1] = 1'b0;
                end

                // ── Step B: AXI beat → wide FIFO ─────────────────────────
                //    One 256-bit word written per accepted beat (single write
                //    port).  The actual register write is in always_ff (Sec 8).
                if (t_valid_i && t_ready_o) begin
                    wfifo_wr_ptr_nxt = wfifo_wr_ptr_nxt + 2'd1;
                    wfifo_count_nxt  = wfifo_count_nxt  + 3'd1;
                end

                // ── Step D: Stage 1 → Aggregator ─────────────────────────
                //    Pack up to four candidates into the aggregator; emit a
                //    48-bit beat every time four coefficients accumulate.
                if (s1_valid && pipe_advance) begin

                    if (s1_d1_av) begin
                        agg_nxt[agg_count_nxt[1:0]] = s1_d1_a;
                        agg_count_nxt   = agg_count_nxt + 3'd1;
                        coeff_count_nxt = coeff_count_nxt + 9'd1;
                        if (agg_count_nxt == 3'd4) begin
                            if (!oq_valid_nxt[0]) begin
                                oq_nxt[0].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[0].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[0] = 1'b1;
                            end else begin
                                oq_nxt[1].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[1].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[1] = 1'b1;
                            end
                            agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                            agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                            agg_count_nxt = 3'd0;
                        end
                    end

                    if (s1_d2_av) begin
                        agg_nxt[agg_count_nxt[1:0]] = s1_d2_a;
                        agg_count_nxt   = agg_count_nxt + 3'd1;
                        coeff_count_nxt = coeff_count_nxt + 9'd1;
                        if (agg_count_nxt == 3'd4) begin
                            if (!oq_valid_nxt[0]) begin
                                oq_nxt[0].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[0].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[0] = 1'b1;
                            end else begin
                                oq_nxt[1].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[1].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[1] = 1'b1;
                            end
                            agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                            agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                            agg_count_nxt = 3'd0;
                        end
                    end

                    if (s1_d1_bv) begin
                        agg_nxt[agg_count_nxt[1:0]] = s1_d1_b;
                        agg_count_nxt   = agg_count_nxt + 3'd1;
                        coeff_count_nxt = coeff_count_nxt + 9'd1;
                        if (agg_count_nxt == 3'd4) begin
                            if (!oq_valid_nxt[0]) begin
                                oq_nxt[0].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[0].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[0] = 1'b1;
                            end else begin
                                oq_nxt[1].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[1].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[1] = 1'b1;
                            end
                            agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                            agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                            agg_count_nxt = 3'd0;
                        end
                    end

                    if (s1_d2_bv) begin
                        agg_nxt[agg_count_nxt[1:0]] = s1_d2_b;
                        agg_count_nxt   = agg_count_nxt + 3'd1;
                        coeff_count_nxt = coeff_count_nxt + 9'd1;
                        if (agg_count_nxt == 3'd4) begin
                            if (!oq_valid_nxt[0]) begin
                                oq_nxt[0].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[0].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[0] = 1'b1;
                            end else begin
                                oq_nxt[1].data  = {agg_nxt[3], agg_nxt[2],
                                                   agg_nxt[1], agg_nxt[0]};
                                oq_nxt[1].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                                oq_valid_nxt[1] = 1'b1;
                            end
                            agg_nxt[0] = 12'd0;  agg_nxt[1] = 12'd0;
                            agg_nxt[2] = 12'd0;  agg_nxt[3] = 12'd0;
                            agg_count_nxt = 3'd0;
                        end
                    end

                    s1_valid_nxt = 1'b0;  // Stage 1 consumed
                end
                // else (pipe_advance == 0): Stage 1 held by default.

                // ── Step E: Stage 0 → Stage 1 + gearbox advance ──────────
                //    Only when the pipeline is not stalled.  Stage-0 candidate
                //    validity is checked against cnt_base = coeff_count after
                //    Stage-1's contribution (computed above in Step D) so that
                //    we never overshoot TARGET_COEFFS.
                if (pipe_advance) begin
                    cnt_base = coeff_count_nxt;  // count after Step D

                    // Stage-0 comparators + 256-limit check
                    s0_d1_av = (d1_a < 12'(Q)) && (cnt_base < 9'(TARGET_COEFFS));
                    s0_d2_av = (d2_a < 12'(Q))
                             && ((cnt_base + {8'b0, s0_d1_av}) < 9'(TARGET_COEFFS));
                    s0_d1_bv = (d1_b < 12'(Q))
                             && ((cnt_base + {8'b0, s0_d1_av}
                                           + {8'b0, s0_d2_av}) < 9'(TARGET_COEFFS));
                    s0_d2_bv = (d2_b < 12'(Q))
                             && ((cnt_base + {8'b0, s0_d1_av}
                                           + {8'b0, s0_d2_av}
                                           + {8'b0, s0_d1_bv}) < 9'(TARGET_COEFFS));

                    if (have_6bytes && (cnt_base < 9'(TARGET_COEFFS))) begin
                        // Latch Stage-0 outputs into the Stage-1 register.
                        s1_valid_nxt  = 1'b1;
                        s1_d1_a_nxt   = d1_a;  s1_d1_av_nxt = s0_d1_av;
                        s1_d2_a_nxt   = d2_a;  s1_d2_av_nxt = s0_d2_av;
                        s1_d1_b_nxt   = d1_b;  s1_d1_bv_nxt = s0_d1_bv;
                        s1_d2_b_nxt   = d2_b;  s1_d2_bv_nxt = s0_d2_bv;

                        // Advance gearbox: consume 6 bytes.
                        // boff_plus6[4:0] == boff_plus6 - 32 when >= 32,
                        // and == boff_plus6 when < 32; both cases are correct.
                        boff_plus6   = {1'b0, gbx_boff} + 6'd6;
                        gbx_boff_nxt = boff_plus6[4:0];

                        if (boff_plus6 >= 6'd32) begin
                            // word0 exhausted: shift word1 into word0.
                            // gbx_word1_nxt still holds gbx_word1 at this
                            // point (Step C has not yet run), so the shift
                            // takes the registered word1 value.
                            gbx_word0_nxt = gbx_word1_nxt;
                            gbx_w0v_nxt   = gbx_w1v_nxt;
                            gbx_w1v_nxt   = 1'b0;   // word1 slot freed for Step C
                        end
                    end else begin
                        s1_valid_nxt = 1'b0;  // Insert bubble
                    end
                end

                // ── Step C: Gearbox refill from wide FIFO ────────────────
                //    Runs after Step E so that a shift (which frees the word1
                //    slot) is visible here and can be immediately re-filled.
                //    Uses wfifo_count (registered, before this cycle's write)
                //    to prevent reading a slot whose write has not yet clocked
                //    in (avoids read-before-write on an empty FIFO).
                //    At most one wide-FIFO read per cycle (single read port).
                if (!gbx_w0v_nxt && wfifo_count > 3'd0) begin
                    gbx_word0_nxt    = wfifo[wfifo_rd_ptr];
                    gbx_w0v_nxt      = 1'b1;
                    wfifo_rd_ptr_nxt = wfifo_rd_ptr_nxt + 2'd1;
                    wfifo_count_nxt  = wfifo_count_nxt  - 3'd1;
                end else if (gbx_w0v_nxt && !gbx_w1v_nxt && wfifo_count > 3'd0) begin
                    gbx_word1_nxt    = wfifo[wfifo_rd_ptr];
                    gbx_w1v_nxt      = 1'b1;
                    wfifo_rd_ptr_nxt = wfifo_rd_ptr_nxt + 2'd1;
                    wfifo_count_nxt  = wfifo_count_nxt  - 3'd1;
                end

                // ── Step F: Completion check ──────────────────────────────
                //    Transition to S_DONE once all coefficients have been
                //    counted AND the entire pipeline (Stage 1 + aggregator +
                //    output queue) is fully drained.
                if ((coeff_count_nxt >= 9'(TARGET_COEFFS))
                    && !oq_valid_nxt[0] && !oq_valid_nxt[1]
                    && (agg_count_nxt == 3'd0)
                    && !s1_valid_nxt) begin
                    state_nxt = S_DONE;
                end

            end // S_RUN

            // -----------------------------------------------------------------
            // DONE — one-cycle done pulse, then back to IDLE.
            // -----------------------------------------------------------------
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
    //    Pure reg <= nxt assignments.
    //    t_ready_o is registered here (Issue 2 fix): it no longer forms a
    //    combinational path from t_ready_i, breaking the cross-module timing
    //    chain described in the review feedback.
    //    The wide FIFO write is a single DWIDTH-bit assignment — one write
    //    port — which allows the synthesis tool to infer a BRAM instead of
    //    a large LUT-based crossbar (Issue 1 fix).

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state        <= S_IDLE;
            done         <= 1'b0;
            t_ready_o    <= 1'b0;
            wfifo_wr_ptr <= 2'd0;
            wfifo_rd_ptr <= 2'd0;
            wfifo_count  <= 3'd0;
            gbx_w0v      <= 1'b0;
            gbx_w1v      <= 1'b0;
            gbx_boff     <= 5'd0;
            s1_valid     <= 1'b0;
            s1_d1_av     <= 1'b0;  s1_d2_av <= 1'b0;
            s1_d1_bv     <= 1'b0;  s1_d2_bv <= 1'b0;
            agg[0]       <= 12'd0;  agg[1] <= 12'd0;
            agg[2]       <= 12'd0;  agg[3] <= 12'd0;
            agg_count    <= 3'd0;
            oq[0]        <= '0;     oq[1]  <= '0;
            oq_valid[0]  <= 1'b0;   oq_valid[1] <= 1'b0;
            coeff_count  <= 9'd0;
        end else begin
            state        <= state_nxt;
            done         <= done_nxt;

            // Registered ready: assert when the FIFO will have room next cycle.
            // This decouples t_ready_o from the combinational path driven by
            // t_ready_i (fixes the long combinational chain noted in review).
            t_ready_o    <= (state_nxt == S_RUN)
                         && (wfifo_count_nxt < 3'(WFIFO_DEPTH));

            wfifo_wr_ptr <= wfifo_wr_ptr_nxt;
            wfifo_rd_ptr <= wfifo_rd_ptr_nxt;
            wfifo_count  <= wfifo_count_nxt;
            gbx_word0    <= gbx_word0_nxt;
            gbx_word1    <= gbx_word1_nxt;
            gbx_w0v      <= gbx_w0v_nxt;
            gbx_w1v      <= gbx_w1v_nxt;
            gbx_boff     <= gbx_boff_nxt;
            s1_valid     <= s1_valid_nxt;
            s1_d1_a      <= s1_d1_a_nxt;   s1_d2_a  <= s1_d2_a_nxt;
            s1_d1_b      <= s1_d1_b_nxt;   s1_d2_b  <= s1_d2_b_nxt;
            s1_d1_av     <= s1_d1_av_nxt;  s1_d2_av <= s1_d2_av_nxt;
            s1_d1_bv     <= s1_d1_bv_nxt;  s1_d2_bv <= s1_d2_bv_nxt;
            agg[0]       <= agg_nxt[0];
            agg[1]       <= agg_nxt[1];
            agg[2]       <= agg_nxt[2];
            agg[3]       <= agg_nxt[3];
            agg_count    <= agg_count_nxt;
            oq[0]        <= oq_nxt[0];
            oq[1]        <= oq_nxt[1];
            oq_valid[0]  <= oq_valid_nxt[0];
            oq_valid[1]  <= oq_valid_nxt[1];
            coeff_count  <= coeff_count_nxt;

            // Wide FIFO write: a single DWIDTH-bit assignment per beat.
            // One write port — BRAM-inference-friendly (Issue 1 fix).
            if (t_valid_i && t_ready_o)
                wfifo[wfifo_wr_ptr] <= t_data_i;
        end
    end

    // =========================================================================
    // 9. ASSERTIONS (simulation only)
    // =========================================================================
    // synthesis translate_off

    // Wide FIFO must never overflow.
    assert property (@(posedge clk) disable iff (rst) wfifo_count <= 3'(WFIFO_DEPTH))
        else $fatal(1, "FIFO count overflow: %0d", wfifo_count);

    // Coefficient counter must never exceed target.
    assert property (@(posedge clk) disable iff (rst) coeff_count <= 9'(TARGET_COEFFS))
        else $fatal(1, "coeff_count overflow: %0d", coeff_count);

    // AXI sink: data/keep/last stable while back-pressured.
    assert property (@(posedge clk) disable iff (rst)
        (t_valid_i && !t_ready_o) |=> $stable(t_data_i) && $stable(t_keep_i) && $stable(t_last_i))
        else $error("AXI sink: signals changed during backpressure");

    // AXI source: output stable while back-pressured.
    assert property (@(posedge clk) disable iff (rst)
        (t_valid_o && !t_ready_i) |=> $stable(t_data_o) && $stable(t_keep_o) && $stable(t_last_o))
        else $error("AXI source: signals changed during backpressure");

    // synthesis translate_on

endmodule
