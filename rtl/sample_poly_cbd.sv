// -----------------------------------------------------------------------------
// Author      : Salwan Aldhahab
// Module      : sample_poly_cbd
// Standard    : FIPS 203 ML-KEM — Algorithm 8 (SamplePolyCBD)
//
// Description :
//   Deterministic sampler that converts a fixed-length byte stream into
//   exactly 256 polynomial coefficients sampled from the centered binomial
//   distribution D_η(R_q), where η ∈ {2, 3} and q = 3329.
//
//   Every ETA bytes (2 for η=2, 3 for η=3) are converted to bits and
//   partitioned into 4 groups of 2η bits.  Within each group the first η
//   bits are summed to give x, the second η bits are summed to give y,
//   and the coefficient is (x − y) mod q.
//
//   Input byte count: 64·η  (128 for η=2, 192 for η=3).
//   Output: 64 beats of 4 × 12-bit packed coefficients (256 total).
//
// Micro-architecture:
//
//   ┌───────────┐   AXI-S sink   ┌────────────┐  ETA-byte  ┌──────────┐
//   │  Keccak   │──────────────▸ │ Byte FIFO  │──────────▸ │   CBD    │
//   │  (SHAKE)  │  256b beats    │ 64 entries │  chunks    │  Sampler │
//   └───────────┘                └────────────┘            └────┬─────┘
//                                                               │ 4 coeffs/cycle
//                                                          ┌────▼─────┐
//                                      AXI-S source        │ Skid Buf │
//                                ◂─────────────────────────│ (2-deep) │
//                                  48-bit beats            └──────────┘
//
//   • Byte FIFO       – 64-byte circular buffer absorbing AXI beats.
//   • CBD sampler      – purely combinational; peeks ETA bytes, produces 4
//                        coefficients via popcount and modular subtraction.
//   • Skid buffer      – 2-entry output queue so the sampler never stalls on
//                        downstream backpressure for a single cycle.
//
// Handshake notes:
//   • t_ready_o is asserted only while the FIFO can accept a full beat.
//   • t_last_o marks the final (64th) output beat carrying coefficients 253–256.
//   • done pulses high for one cycle after all 256 coefficients have been
//     emitted and the output queue is fully drained.
// -----------------------------------------------------------------------------

module sample_poly_cbd #(
    parameter int ETA        = 2,              // CBD parameter η ∈ {2, 3}
    parameter int DWIDTH     = 256,            // Input AXI beat width (bits)
    parameter int KEEP_WIDTH = DWIDTH / 8      // Byte-enable width
) (
    input  wire                      clk,
    input  wire                      rst,

    // Control
    input  wire                      start,    // Pulse to begin sampling
    output logic                     done,     // Pulse when 256 coefficients delivered

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

    localparam int Q              = 3329;        // ML-KEM modulus
    localparam int TARGET_COEFFS  = 256;         // Polynomial degree
    localparam int FIFO_DEPTH     = 64;          // Byte FIFO depth
    localparam int CHUNK_BYTES    = ETA;         // Bytes consumed per 4 coefficients

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
    // 5. COMBINATIONAL: CBD Sampling (peek CHUNK_BYTES from FIFO)
    // =========================================================================

    // Parameterised popcount over ETA bits (max return value = ETA ≤ 3).
    function automatic logic [1:0] popcount_eta(input logic [ETA-1:0] bits);
        logic [1:0] sum;
        sum = 2'd0;
        for (int i = 0; i < ETA; i++)
            sum = sum + {1'b0, bits[i]};
        return sum;
    endfunction

    logic                have_chunk;
    logic [8*ETA-1:0]    raw_bits;     // ETA bytes concatenated (LSB-first)
    logic [1:0]          cbd_x [4];
    logic [1:0]          cbd_y [4];
    logic [11:0]         cbd_coeff [4];

    always_comb begin
        have_chunk = (fifo_count >= 7'(CHUNK_BYTES));

        // Peek CHUNK_BYTES bytes from FIFO (wrapping via 6-bit truncation)
        raw_bits = '0;
        for (int b = 0; b < ETA; b++)
            raw_bits[8*b +: 8] = fifo[6'(fifo_rd_ptr + b)];

        // Compute 4 coefficients: each uses 2·ETA bits
        for (int k = 0; k < 4; k++) begin
            cbd_x[k] = popcount_eta(raw_bits[2*ETA*k       +: ETA]);
            cbd_y[k] = popcount_eta(raw_bits[2*ETA*k + ETA +: ETA]);

            if (cbd_x[k] >= cbd_y[k])
                cbd_coeff[k] = 12'(cbd_x[k] - cbd_y[k]);
            else
                cbd_coeff[k] = 12'(Q) - 12'(cbd_y[k] - cbd_x[k]);
        end
    end

    // =========================================================================
    // 6. COMBINATIONAL: Next-State Logic
    // =========================================================================

    logic        fifo_wr_en   [KEEP_WIDTH];
    logic [5:0]  fifo_wr_addr [KEEP_WIDTH];

    state_t      state_nxt;
    logic        done_nxt;
    logic [6:0]  fifo_count_nxt;
    logic [5:0]  fifo_wr_ptr_nxt;
    logic [5:0]  fifo_rd_ptr_nxt;
    beat_t       oq_nxt       [2];
    logic        oq_valid_nxt [2];
    logic [8:0]  coeff_count_nxt;

    logic [1:0]  oq_free_after_deq;
    logic        can_process;

    always_comb begin
        // -- Defaults: hold current value --
        state_nxt        = state;
        done_nxt         = 1'b0;
        fifo_count_nxt   = fifo_count;
        fifo_wr_ptr_nxt  = fifo_wr_ptr;
        fifo_rd_ptr_nxt  = fifo_rd_ptr;
        oq_nxt[0]        = oq[0]; oq_nxt[1] = oq[1];
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
            S_IDLE: begin
                if (start) begin
                    state_nxt        = S_RUN;
                    fifo_count_nxt   = 7'd0;
                    fifo_wr_ptr_nxt  = 6'd0;
                    fifo_rd_ptr_nxt  = 6'd0;
                    oq_nxt[0] = '0; oq_nxt[1] = '0;
                    oq_valid_nxt[0]  = 1'b0;
                    oq_valid_nxt[1]  = 1'b0;
                    coeff_count_nxt  = 9'd0;
                end
            end

            S_RUN: begin
                // Step A: Output dequeue
                if (oq_valid_nxt[0] && t_ready_i) begin
                    oq_nxt[0]       = oq_nxt[1];
                    oq_valid_nxt[0] = oq_valid_nxt[1];
                    oq_valid_nxt[1] = 1'b0;
                end

                // Step B: FIFO enqueue
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

                // Step C: CBD sampling & packing (always produces exactly 4 coeffs)
                oq_free_after_deq = 2'd2 - {1'b0, oq_valid_nxt[0]}
                                         - {1'b0, oq_valid_nxt[1]};

                can_process = have_chunk
                            && (oq_free_after_deq >= 2'd1)
                            && (coeff_count_nxt < 9'(TARGET_COEFFS));

                if (can_process) begin
                    fifo_rd_ptr_nxt = fifo_rd_ptr_nxt + 6'(CHUNK_BYTES);
                    fifo_count_nxt  = fifo_count_nxt  - 7'(CHUNK_BYTES);
                    coeff_count_nxt = coeff_count_nxt + 9'd4;

                    if (!oq_valid_nxt[0]) begin
                        oq_nxt[0].data  = {cbd_coeff[3], cbd_coeff[2],
                                            cbd_coeff[1], cbd_coeff[0]};
                        oq_nxt[0].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                        oq_valid_nxt[0] = 1'b1;
                    end else begin
                        oq_nxt[1].data  = {cbd_coeff[3], cbd_coeff[2],
                                            cbd_coeff[1], cbd_coeff[0]};
                        oq_nxt[1].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                        oq_valid_nxt[1] = 1'b1;
                    end
                end

                // Step D: Completion check
                if ((coeff_count_nxt >= 9'(TARGET_COEFFS))
                    && !oq_valid_nxt[0] && !oq_valid_nxt[1]) begin
                    state_nxt = S_DONE;
                end
            end

            S_DONE: begin
                done_nxt  = 1'b1;
                state_nxt = S_IDLE;
            end

            default: state_nxt = S_IDLE;
        endcase
    end

    // =========================================================================
    // 7. SEQUENTIAL: Register Update
    // =========================================================================

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= S_IDLE;
            done        <= 1'b0;
            fifo_count  <= 7'd0;
            fifo_wr_ptr <= 6'd0;
            fifo_rd_ptr <= 6'd0;
            oq[0] <= '0; oq[1] <= '0;
            oq_valid[0] <= 1'b0; oq_valid[1] <= 1'b0;
            coeff_count <= 9'd0;
        end else begin
            state       <= state_nxt;
            done        <= done_nxt;
            fifo_count  <= fifo_count_nxt;
            fifo_wr_ptr <= fifo_wr_ptr_nxt;
            fifo_rd_ptr <= fifo_rd_ptr_nxt;
            oq[0] <= oq_nxt[0]; oq[1] <= oq_nxt[1];
            oq_valid[0] <= oq_valid_nxt[0];
            oq_valid[1] <= oq_valid_nxt[1];
            coeff_count <= coeff_count_nxt;

            for (int i = 0; i < KEEP_WIDTH; i++) begin
                if (fifo_wr_en[i])
                    fifo[fifo_wr_addr[i]] <= t_data_i[8*i +: 8];
            end
        end
    end

endmodule
