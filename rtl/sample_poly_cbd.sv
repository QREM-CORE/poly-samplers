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
    input  wire                      start,
    output logic                     done,

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
    localparam int CHUNK_BYTES   = ETA; 
    localparam int WFIFO_DEPTH   = 4;

    typedef enum logic [1:0] {
        S_IDLE, S_RUN, S_DONE
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
    // 4. COMBINATIONAL: Gearbox ETA-byte read window
    // =========================================================================
    logic [8:0]       gbx_bit_ptr;
    logic [8*ETA-1:0] eta_bytes;
    logic             have_eta_bytes;

    always_comb begin
        gbx_bit_ptr    = {1'b0, gbx_boff, 3'b000}; 
        eta_bytes      = {gbx_word1, gbx_word0}[gbx_bit_ptr +: 8*ETA];
        // Valid if word0 is valid AND (the chunk fits entirely in word0 OR word1 is also valid)
        have_eta_bytes = gbx_w0v && (({1'b0, gbx_boff} + 6'(CHUNK_BYTES)) <= 6'd32 || gbx_w1v);
    end

    // =========================================================================
    // 5. COMBINATIONAL: CBD Sampling (Using Math from V1)
    // =========================================================================
    function automatic logic [1:0] popcount_eta(input logic [ETA-1:0] bits);
        logic [1:0] sum;
        sum = 2'd0;
        for (int i = 0; i < ETA; i++) sum = sum + {1'b0, bits[i]};
        return sum;
    endfunction

    logic [1:0]  cbd_x [4];
    logic [1:0]  cbd_y [4];
    logic [11:0] cbd_coeff [4];

    always_comb begin
        // The math logic stays identical, but we directly use eta_bytes from the gearbox!
        for (int k = 0; k < 4; k++) begin
            cbd_x[k] = popcount_eta(eta_bytes[2*ETA*k       +: ETA]);
            cbd_y[k] = popcount_eta(eta_bytes[2*ETA*k + ETA +: ETA]);

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
    logic                done_nxt;
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
        done_nxt         = 1'b0;
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
                can_emit = have_eta_bytes && !oq_full && (coeff_count_nxt < 9'(TARGET_COEFFS));

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

                    // Advance gearbox by CHUNK_BYTES (ETA)
                    boff_plus_chunk = {1'b0, gbx_boff} + 6'(CHUNK_BYTES);
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
                    state_nxt = S_DONE;
                end
            end

            S_DONE: begin
                done_nxt  = 1'b1;
                state_nxt = S_IDLE;
            end
        endcase
    end

    // =========================================================================
    // 7. SEQUENTIAL
    // =========================================================================
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
            oq[0]        <= '0; oq[1] <= '0;
            oq_valid[0]  <= 1'b0; oq_valid[1] <= 1'b0;
            coeff_count  <= 9'd0;
        end else begin
            state        <= state_nxt;
            done         <= done_nxt;
            
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

            if (t_valid_i && t_ready_o)
                wfifo[wfifo_wr_ptr] <= t_data_i;
        end
    end

endmodule
