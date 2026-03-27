// -----------------------------------------------------------------------------
// Author      : Salwan Aldhahab, Kiet Le
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
//   Unified Architecture: Supports both η=2 and η=3 at runtime via the
//   `is_eta3` control signal.
//
//   Input byte count: 64·η  (128 for η=2, 192 for η=3).
//   Output: 64 beats of 4 × 12-bit packed coefficients (256 total).
//
// Micro-architecture (revised):
//
//   ┌───────────┐   AXI-S sink   ┌────────────┐  256-bit words  ┌──────────┐
//   │  Keccak   │──────────────▸ │ Wide FIFO  │───────────────▸ │ Gearbox  │
//   │  (SHAKE)  │  256b beats    │ 4 entries  │  1 read/cycle   │ 24b/cycle│
//   └───────────┘  1 write/beat  └────────────┘                 └────┬─────┘
//                                                                    │ 24 bits (max 3 bytes)
//                                                              ┌─────▼─────┐
//                                                              │  Dynamic  │
//                                                              │  Mux &    │
//                                                              │  Popcount │
//                                                              └─────┬─────┘
//                                                                    │ 4 coeffs/cycle
//                                      AXI-S source            ┌─────▼─────┐
//                                ◂──────────────────────────── │ 4-coeff   │
//                                  48-bit beats                │ Skid Buf  │
//                                                              └───────────┘
//
//   • Wide FIFO    – 4 × 256-bit word entries.  Each AXI beat is stored with a
//                    single DWIDTH-bit write (one write port, BRAM-friendly).
//   • Gearbox      – double-buffer (word0 + word1).  Reads a fixed 24-bit
//                    window per cycle via a variable part-select; handles
//                    cross-word-boundary spans transparently.
//   • Dynamic Mux  – routes exactly 16 bits (η=2) or 24 bits (η=3) from the
//     & Popcount     gearbox into a unified 3-bit popcount and modulo logic.
//                    Produces exactly 4 coefficients per cycle.
//   • Skid buffer  – 2-entry output queue absorbs downstream back-pressure.
//
// Handshake notes:
//   • t_ready_o is registered — one-cycle latency between an internal count
//     change and the upstream source seeing back-pressure.
//   • t_last_o marks the final (64th) output beat (coefficients 253-256).
//   • done pulses high for one cycle after all 256 coefficients are delivered,
//     the output queue is drained, and the pipeline is empty.
// -----------------------------------------------------------------------------

module sample_poly_cbd #(
    parameter int DWIDTH     = 256,            // Input AXI beat width (bits)
    parameter int KEEP_WIDTH = DWIDTH / 8      // Byte-enable width
) (
    input  wire                      clk,
    input  wire                      rst,

    // Control
    input  wire                      start,
    input  wire                      is_eta3,  // 1 = ML-KEM-768/1024 (η=3), 0 = ML-KEM-512 (η=2)

    // AXI4-Stream Sink
    input  wire  [DWIDTH-1:0]        t_data_i,
    input  wire                      t_valid_i,
    input  wire                      t_last_i,
    input  wire  [KEEP_WIDTH-1:0]    t_keep_i,
    output logic                     t_ready_o,

    // AXI4-Stream Source
    output logic [47:0]              t_data_o,
    output logic                     t_valid_o,
    output logic                     t_last_o,
    output logic [5:0]               t_keep_o,
    input  wire                      t_ready_i
);

    // =========================================================================
    // 1. PARAMETERS & TYPES
    // =========================================================================
    localparam int Q             = 3329;
    localparam int TARGET_COEFFS = 256;
    localparam int WFIFO_DEPTH   = 4;

    typedef enum logic [1:0] {
        S_IDLE, S_RUN
    } state_t;

    typedef struct packed {
        logic [47:0] data;
        logic        last;
    } beat_t;

    // =========================================================================
    // 2. REGISTERS
    // =========================================================================
    state_t state;

    // Wide word FIFO
    logic [DWIDTH-1:0]  wfifo [WFIFO_DEPTH];
    logic [1:0]         wfifo_wr_ptr;
    logic [1:0]         wfifo_rd_ptr;
    logic [2:0]         wfifo_count;

    // Gearbox double-buffer
    logic [DWIDTH-1:0]  gbx_word0;
    logic [DWIDTH-1:0]  gbx_word1;
    logic               gbx_w0v;
    logic               gbx_w1v;
    logic [4:0]         gbx_boff;

    // 2-entry output skid buffer
    beat_t              oq      [2];
    logic               oq_valid[2];

    // Global progress
    logic [8:0]         coeff_count;

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
    // 4. COMBINATIONAL: Gearbox Dynamic Read Window
    // =========================================================================
    logic [8:0]  gbx_bit_ptr;
    logic [23:0] raw_chunk; // Always extract 24 bits (3 bytes max)
    logic        have_chunk;
    logic [2:0]  chunk_size; // Dynamically 2 or 3

    always_comb begin
        chunk_size  = is_eta3 ? 3'd3 : 3'd2;
        gbx_bit_ptr = {1'b0, gbx_boff, 3'b000};

        // Extract maximum possible chunk to avoid variable width slicing
        raw_chunk   = {gbx_word1, gbx_word0}[gbx_bit_ptr +: 24];

        have_chunk  = gbx_w0v && (({1'b0, gbx_boff} + 6'(chunk_size)) <= 6'd32 || gbx_w1v);
    end

    // =========================================================================
    // 5. COMBINATIONAL: CBD Sampling (Unified Multiplexer)
    // =========================================================================

    // Fixed 3-bit popcount. If η=2, the top bit is padded with 0.
    function automatic logic [1:0] popcount3(input logic [2:0] bits);
        return {1'b0, bits[0]} + {1'b0, bits[1]} + {1'b0, bits[2]};
    endfunction

    logic [2:0]  x_bits [4];
    logic [2:0]  y_bits [4];
    logic [1:0]  cbd_x  [4];
    logic [1:0]  cbd_y  [4];
    logic [11:0] cbd_coeff [4];

    always_comb begin
        // Multiplex bits based on current ETA security parameter
        if (is_eta3) begin
            // η=3: Use all 24 bits
            x_bits[0] = raw_chunk[2:0];   y_bits[0] = raw_chunk[5:3];
            x_bits[1] = raw_chunk[8:6];   y_bits[1] = raw_chunk[11:9];
            x_bits[2] = raw_chunk[14:12]; y_bits[2] = raw_chunk[17:15];
            x_bits[3] = raw_chunk[20:18]; y_bits[3] = raw_chunk[23:21];
        end else begin
            // η=2: Use 16 bits, pad MSB of each group with 0
            x_bits[0] = {1'b0, raw_chunk[1:0]};   y_bits[0] = {1'b0, raw_chunk[3:2]};
            x_bits[1] = {1'b0, raw_chunk[5:4]};   y_bits[1] = {1'b0, raw_chunk[7:6]};
            x_bits[2] = {1'b0, raw_chunk[9:8]};   y_bits[2] = {1'b0, raw_chunk[11:10]};
            x_bits[3] = {1'b0, raw_chunk[13:12]}; y_bits[3] = {1'b0, raw_chunk[15:14]};
        end

        // Compute Coefficients
        for (int k = 0; k < 4; k++) begin
            cbd_x[k] = popcount3(x_bits[k]);
            cbd_y[k] = popcount3(y_bits[k]);

            if (cbd_x[k] >= cbd_y[k])
                cbd_coeff[k] = 12'(cbd_x[k] - cbd_y[k]);
            else
                cbd_coeff[k] = 12'(Q) - 12'(cbd_y[k] - cbd_x[k]);
        end
    end

    // =========================================================================
    // 6. COMBINATIONAL: Next-State Logic
    // =========================================================================
    state_t              state_nxt;
    logic [1:0]          wfifo_wr_ptr_nxt;
    logic [1:0]          wfifo_rd_ptr_nxt;
    logic [2:0]          wfifo_count_nxt;
    logic [DWIDTH-1:0]   gbx_word0_nxt, gbx_word1_nxt;
    logic                gbx_w0v_nxt, gbx_w1v_nxt;
    logic [4:0]          gbx_boff_nxt;
    beat_t               oq_nxt  [2];
    logic                oq_valid_nxt [2];
    logic [8:0]          coeff_count_nxt;

    logic [5:0]          boff_plus_chunk;
    logic                can_emit;
    logic                oq_full;

    always_comb begin
        state_nxt        = state;
        wfifo_wr_ptr_nxt = wfifo_wr_ptr;
        wfifo_rd_ptr_nxt = wfifo_rd_ptr;
        wfifo_count_nxt  = wfifo_count;
        gbx_word0_nxt    = gbx_word0;
        gbx_word1_nxt    = gbx_word1;
        gbx_w0v_nxt      = gbx_w0v;
        gbx_w1v_nxt      = gbx_w1v;
        gbx_boff_nxt     = gbx_boff;
        oq_nxt[0]        = oq[0];
        oq_nxt[1]        = oq[1];
        oq_valid_nxt[0]  = oq_valid[0];
        oq_valid_nxt[1]  = oq_valid[1];
        coeff_count_nxt  = coeff_count;

        boff_plus_chunk  = 6'd0;

        case (state)
            S_IDLE: begin
                if (start) begin
                    state_nxt        = S_RUN;
                    wfifo_wr_ptr_nxt = 2'd0;
                    wfifo_rd_ptr_nxt = 2'd0;
                    wfifo_count_nxt  = 3'd0;
                    gbx_w0v_nxt      = 1'b0;
                    gbx_w1v_nxt      = 1'b0;
                    gbx_boff_nxt     = 5'd0;
                    oq_nxt[0]        = '0; oq_nxt[1] = '0;
                    oq_valid_nxt[0]  = 1'b0; oq_valid_nxt[1] = 1'b0;
                    coeff_count_nxt  = 9'd0;
                end
            end

            S_RUN: begin
                // Step A: Output Dequeue
                if (oq_valid_nxt[0] && t_ready_i) begin
                    oq_nxt[0]       = oq_nxt[1];
                    oq_valid_nxt[0] = oq_valid_nxt[1];
                    oq_valid_nxt[1] = 1'b0;
                end

                // Step B: FIFO Enqueue
                if (t_valid_i && t_ready_o) begin
                    wfifo_wr_ptr_nxt = wfifo_wr_ptr_nxt + 2'd1;
                    wfifo_count_nxt  = wfifo_count_nxt  + 3'd1;
                end

                // Step C & D: CBD Sampling, Packing, and Gearbox Advance
                oq_full  = oq_valid_nxt[0] && oq_valid_nxt[1];
                can_emit = have_chunk && !oq_full && (coeff_count_nxt < 9'(TARGET_COEFFS));

                if (can_emit) begin
                    // Emit exactly 4 coefficients
                    coeff_count_nxt = coeff_count_nxt + 9'd4;

                    if (!oq_valid_nxt[0]) begin
                        oq_nxt[0].data  = {cbd_coeff[3], cbd_coeff[2], cbd_coeff[1], cbd_coeff[0]};
                        oq_nxt[0].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                        oq_valid_nxt[0] = 1'b1;
                    end else begin
                        oq_nxt[1].data  = {cbd_coeff[3], cbd_coeff[2], cbd_coeff[1], cbd_coeff[0]};
                        oq_nxt[1].last  = (coeff_count_nxt == 9'(TARGET_COEFFS));
                        oq_valid_nxt[1] = 1'b1;
                    end

                    // Advance gearbox dynamically by 2 or 3 bytes
                    boff_plus_chunk = {1'b0, gbx_boff} + 6'(chunk_size);
                    gbx_boff_nxt    = boff_plus_chunk[4:0];

                    if (boff_plus_chunk >= 6'd32) begin
                        gbx_word0_nxt = gbx_word1_nxt;
                        gbx_w0v_nxt   = gbx_w1v_nxt;
                        gbx_w1v_nxt   = 1'b0;
                    end
                end

                // Step E: Gearbox Refill from FIFO
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

                // Step F: Completion Check
                if ((coeff_count_nxt >= 9'(TARGET_COEFFS)) && !oq_valid_nxt[0] && !oq_valid_nxt[1]) begin
                    state_nxt = S_IDLE;
                end
            end
        endcase
    end

    // =========================================================================
    // 7. SEQUENTIAL
    // =========================================================================
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state        <= S_IDLE;
            t_ready_o    <= 1'b0;
            wfifo_wr_ptr <= 2'd0;
            wfifo_rd_ptr <= 2'd0;
            wfifo_count  <= 3'd0;
            gbx_w0v      <= 1'b0;
            gbx_w1v      <= 1'b0;
            gbx_boff     <= 5'd0;
            oq[0]        <= '0; oq[1] <= '0;
            oq_valid[0]  <= 1'b0; oq_valid[1] <= 1'b0;
            coeff_count  <= 9'd0;
        end else begin
            state        <= state_nxt;

            t_ready_o    <= (state_nxt == S_RUN) && (wfifo_count_nxt < 3'(WFIFO_DEPTH));

            wfifo_wr_ptr <= wfifo_wr_ptr_nxt;
            wfifo_rd_ptr <= wfifo_rd_ptr_nxt;
            wfifo_count  <= wfifo_count_nxt;
            gbx_word0    <= gbx_word0_nxt;
            gbx_word1    <= gbx_word1_nxt;
            gbx_w0v      <= gbx_w0v_nxt;
            gbx_w1v      <= gbx_w1v_nxt;
            gbx_boff     <= gbx_boff_nxt;
            oq[0]        <= oq_nxt[0]; oq[1] <= oq_nxt[1];
            oq_valid[0]  <= oq_valid_nxt[0]; oq_valid[1] <= oq_valid_nxt[1];
            coeff_count  <= coeff_count_nxt;

            if (t_valid_i && t_ready_o) begin
                wfifo[wfifo_wr_ptr] <= t_data_i;
            end
        end
    end

endmodule
