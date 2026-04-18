/*
 * Author      : Salwan Aldhahab, Kiet Le
 * Module      : sample_ntt
 * Standard    : FIPS 203 ML-KEM — Algorithm 7 (SampleNTT)
 *
 * Description :
 *   Rejection sampler that converts a SHAKE-128 byte stream into exactly
 *   256 NTT-domain coefficients in Z_q (q = 3329).
 *
 *   Every 3 input bytes (b0, b1, b2) produce two 12-bit candidates:
 *       d1 = b0 + 256 * (b1 mod 16)
 *       d2 = (b1 / 16) + 16 * b2
 *   Candidates are accepted if < 3329. Rejected candidates are discarded.
 *   Accepted coefficients are aggregated and emitted four at a time via
 *   the memory writer interface.
 *
 * Micro-architecture :
 *   * Wide FIFO : 4-entry, DWIDTH-bit FIFO that absorbs AXI4-Stream beats
 *                 using a single write port to facilitate BRAM inference.
 *   * Gearbox   : 128-bit double-buffer that extracts a continuous 6-byte
 *                 read window per cycle, handling cross-word spans.
 *   * Stage 0   : Combinational logic that decodes two triples (4 candidates)
 *                 in parallel and performs modulus evaluation.
 *   * Stage 1   : Pipeline register that latches Stage 0 outputs to break
 *                 combinational timing paths before aggregation.
 *   * Packer    : 8-slot accumulation buffer that gathers valid coefficients
 *                 from Stage 1 and dispatches 4-coefficient memory writes.
 *
 * Handshake & Flow Control :
 *   * t_ready_o is registered to decouple upstream combinational paths.
 *   * done_o pulses high for one cycle once all 256 coefficients are
 *     delivered and the pipeline has completely drained.
 */

module sample_ntt #(
    parameter int DWIDTH      = 64,           // Input AXI beat width (bits)
    parameter int KEEP_WIDTH  = DWIDTH / 8,   // Byte-enable width
    parameter int COEFF_W     = 12,           // Coefficient data width
    parameter int NCOEFF      = 256,          // Polynomial degree
    parameter int COEFF_IDX_W = $clog2(NCOEFF)// Index width (8 for 256)
) (
    input  wire                      clk,
    input  wire                      rst,

    // Control
    input  wire                      start,   // Pulse to begin sampling

    // AXI4-Stream Sink (from Keccak / SHAKE source)
    input  wire  [DWIDTH-1:0]        t_data_i,
    input  wire                      t_valid_i,
    input  wire                      t_last_i,
    input  wire  [KEEP_WIDTH-1:0]    t_keep_i,
    output logic                     t_ready_o,

    // Poly Memory Writer Interface
    output logic [3:0]                         wr_en_o,
    output logic [3:0][COEFF_IDX_W-1:0]        wr_idx_o,
    output logic [3:0][COEFF_W-1:0]            wr_data_o,
    output logic                               wr_valid_o,
    output logic                               done_o,
    input  wire                                stall_i
);

    // =========================================================================
    // 1. PARAMETERS & TYPES
    // =========================================================================

    localparam int Q             = 3329;  // Kyber modulus
    localparam int TARGET_COEFFS = 256;   // Polynomial degree
    localparam int WFIFO_DEPTH   = 4;     // Wide FIFO depth (4 × 256-bit words)

    typedef enum logic [1:0] {
        S_IDLE,
        S_RUN
    } state_t;


    // =========================================================================
    // 2. REGISTERS
    // =========================================================================

    // -- FSM --
    state_t state;

    // -- Word FIFO (single write port per AXI beat) --
    // Each AXI beat is written as one DWIDTH-bit word — exactly one write
    // port.
    logic [DWIDTH-1:0]  wfifo [WFIFO_DEPTH];
    logic [1:0]         wfifo_wr_ptr;
    logic [1:0]         wfifo_rd_ptr;
    logic [2:0]         wfifo_count;   // 0 .. 4

    // -- Gearbox double-buffer --
    // Holds at most two DWIDTH-bit words so that a 6-byte read can span a
    // word boundary without stalling.  A variable part-select extracts the window.
    logic [DWIDTH-1:0]  gbx_word0;     // Word being consumed
    logic [DWIDTH-1:0]  gbx_word1;     // Pre-fetched next word
    logic               gbx_w0v;       // word0 is valid
    logic               gbx_w1v;       // word1 is valid
    logic [2:0]         gbx_boff;      // Byte offset within word0 (0 .. 7)

    // -- Pipeline Stage 1 (registered comparator outputs) --
    // Latches the 4 candidate values and their validity flags from Stage 0.
    // This register breaks the deep combinational path through the comparators.
    logic               s1_valid;
    logic [11:0]        s1_d1_a, s1_d2_a, s1_d1_b, s1_d2_b;
    logic               s1_d1_av, s1_d2_av, s1_d1_bv, s1_d2_bv;


    // -- Packer Buffer (8 slots to handle 4 input + 4 already there) --
    logic [7:0][COEFF_W-1:0] packer_buf;
    logic [3:0]              packer_count; // 0 .. 8

    // -- Global progress --
    logic [8:0]  coeff_count;   // 0 .. 256  (9 bits)

    // =========================================================================
    // 3. COMBINATIONAL: Poly Memory Writer Output
    // =========================================================================

    always_comb begin
        automatic logic [8:0] emitted_count = coeff_count - 9'(packer_count);

        // Standard 4-wide beats
        wr_valid_o = (packer_count >= 4);
        wr_en_o    = wr_valid_o ? 4'b1111 : 4'b0000;
        wr_data_o  = {packer_buf[3], packer_buf[2], packer_buf[1], packer_buf[0]};

        // Final flush: if sampling is complete, emit whatever is left
        if ((coeff_count >= 9'(NCOEFF)) && (packer_count > 0)) begin
            wr_valid_o = 1'b1;
            case (packer_count)
                4'd1: wr_en_o = 4'b0001;
                4'd2: wr_en_o = 4'b0011;
                4'd3: wr_en_o = 4'b0111;
                default: wr_en_o = 4'b1111;
            endcase
        end

        wr_idx_o[0] = emitted_count[COEFF_IDX_W-1:0];
        wr_idx_o[1] = emitted_count[COEFF_IDX_W-1:0] + 8'd1;
        wr_idx_o[2] = emitted_count[COEFF_IDX_W-1:0] + 8'd2;
        wr_idx_o[3] = emitted_count[COEFF_IDX_W-1:0] + 8'd3;

        done_o = (coeff_count >= 9'(NCOEFF)) && (packer_count == 0) && !s1_valid;
    end

    // =========================================================================
    // 4. COMBINATIONAL: Gearbox 6-byte read window
    // =========================================================================
    //    The double-buffer is viewed as a contiguous 128-bit word:
    //      {gbx_word1, gbx_word0}.
    //    A byte-aligned MUX extracts the current 6-byte window based on gbx_boff.
    //    Because the window advances by 6 bytes and the word holds 8 bytes,
    //    gbx_boff only ever takes the values 0, 2, 4, 6.
    //    The read is valid only when word0 is loaded AND the 6 bytes either
    //    lie entirely in word0 (boff + 6 <= 8) or word1 is also loaded.

    logic [127:0] double_word;  // 128-bit double-buffer
    logic [47:0]  six_bytes;    // 6-byte window extracted from the double-buffer
    logic         have_6bytes;  // Gearbox can serve a complete 6-byte window

    always_comb begin
        double_word = {gbx_word1, gbx_word0};

        case (gbx_boff)
            3'd0: six_bytes = double_word[0  +: 48];
            3'd2: six_bytes = double_word[16 +: 48];
            3'd4: six_bytes = double_word[32 +: 48];
            3'd6: six_bytes = double_word[48 +: 48];
            default: six_bytes = 48'd0;
        endcase

        have_6bytes = gbx_w0v
                    && (({1'b0, gbx_boff} + 4'd6) <= 4'd8 || gbx_w1v);
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
    logic        s1_stall;       // Stage 1 cannot drain this cycle
    logic        pipe_advance;   // Pipeline is free to advance

    always_comb begin
        s1_accepted  = {2'b0, s1_d1_av} + {2'b0, s1_d2_av}
                     + {2'b0, s1_d1_bv} + {2'b0, s1_d2_bv};

        // Stall pipeline if packer potentially overflows.
        // Even if we emit 4 this cycle, we only have room for 4 more.
        s1_stall     = s1_valid && (packer_count > 4'd4) && stall_i;
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
    logic [1:0]  wfifo_wr_ptr_nxt;
    logic [1:0]  wfifo_rd_ptr_nxt;
    logic [2:0]  wfifo_count_nxt;
    logic [DWIDTH-1:0] gbx_word0_nxt, gbx_word1_nxt;
    logic        gbx_w0v_nxt, gbx_w1v_nxt;
    logic [2:0]  gbx_boff_nxt;
    logic        s1_valid_nxt;
    logic [11:0] s1_d1_a_nxt, s1_d2_a_nxt, s1_d1_b_nxt, s1_d2_b_nxt;
    logic        s1_d1_av_nxt, s1_d2_av_nxt, s1_d1_bv_nxt, s1_d2_bv_nxt;
    logic [8:0]  coeff_count_nxt;
    logic [7:0][11:0] packer_buf_nxt;
    logic [3:0]       packer_count_nxt;

    // -- Working signals (combinational, no register) --
    logic [3:0]  boff_plus6;   // gbx_boff + 6, 4-bit to detect wraparound at 8
    logic [8:0]  cnt_base;     // coeff_count after Stage-1 contribution (for Stage-0 validity)
    logic        s0_d1_av, s0_d2_av, s0_d1_bv, s0_d2_bv;  // Stage-0 candidate validity

    always_comb begin

        // ── Defaults: hold registered values ─────────────────────────────
        state_nxt        = state;
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
        coeff_count_nxt  = coeff_count;
        packer_buf_nxt   = packer_buf;
        packer_count_nxt = packer_count;

        boff_plus6 = 4'd0;
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
                    gbx_boff_nxt     = 3'd0;
                    s1_valid_nxt     = 1'b0;
                    coeff_count_nxt  = 9'd0;
                    packer_count_nxt = 4'd0;
                end
            end

            // -----------------------------------------------------------------
            // RUN — pipeline: dequeue → write → packer → sample → refill
            // -----------------------------------------------------------------
            S_RUN: begin

                // ── Step B: AXI beat → wide FIFO ─────────────────────────
                //    One 256-bit word written per accepted beat (single write
                //    port).  The actual register write is in always_ff (Sec 8).
                if (t_valid_i && t_ready_o) begin
                    wfifo_wr_ptr_nxt = wfifo_wr_ptr_nxt + 2'd1;
                    wfifo_count_nxt  = wfifo_count_nxt  + 3'd1;
                end

                if (s1_valid && pipe_advance) begin
                    coeff_count_nxt = coeff_count + {6'b0, s1_accepted};
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
                    // d < 3329 (0xD01) is equivalent to: d[11:8] < 0xD || d == 0xD00
                    s0_d1_av = ((d1_a[11:8] < 4'hD) || (d1_a == 12'hD00)) && (cnt_base < 9'(TARGET_COEFFS));
                    s0_d2_av = ((d2_a[11:8] < 4'hD) || (d2_a == 12'hD00))
                             && ((cnt_base + {8'b0, s0_d1_av}) < 9'(TARGET_COEFFS));
                    s0_d1_bv = ((d1_b[11:8] < 4'hD) || (d1_b == 12'hD00))
                             && ((cnt_base + {8'b0, s0_d1_av}
                                           + {8'b0, s0_d2_av}) < 9'(TARGET_COEFFS));
                    s0_d2_bv = ((d2_b[11:8] < 4'hD) || (d2_b == 12'hD00))
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
                        boff_plus6   = {1'b0, gbx_boff} + 4'd6;
                        gbx_boff_nxt = boff_plus6[2:0];

                        if (boff_plus6 >= 4'd8) begin
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
                //    Transition to S_IDLE once all coefficients have been
                //    counted AND the pipeline is drained.
                if ((coeff_count_nxt >= 9'(TARGET_COEFFS))
                    && !s1_valid_nxt
                    && (packer_count_nxt == 0)) begin
                    state_nxt = S_IDLE;
                end

            end // S_RUN

            default: state_nxt = S_IDLE;
        endcase

        // ── Step D2: Packer Logic (Outside Case) ─────────────────────────
        begin
            automatic int pop_cnt = 0;
            automatic int push_cnt = 0;
            automatic logic [7:0][11:0] tmp_buf;

            // 1. Determine Pop
            if (wr_valid_o && !stall_i) begin
                pop_cnt = (packer_count >= 4) ? 4 : int'(packer_count);
            end

            // 2. Shift Buffer
            for (int i = 0; i < 8; i++) begin
                if (i < (8 - pop_cnt))
                    tmp_buf[i] = packer_buf[i + pop_cnt];
                else
                    tmp_buf[i] = '0;
            end

            // 3. Determine Push (only in S_RUN and if pipe advances)
            if (state == S_RUN && s1_valid && pipe_advance) begin
                automatic logic [11:0] in_vals [4];
                automatic logic [3:0]  in_v;
                in_vals[0] = s1_d1_a;  in_v[0] = s1_d1_av;
                in_vals[1] = s1_d2_a;  in_v[1] = s1_d2_av;
                in_vals[2] = s1_d1_b;  in_v[2] = s1_d1_bv;
                in_vals[3] = s1_d2_b;  in_v[3] = s1_d2_bv;

                for (int i = 0; i < 4; i++) begin
                    if (in_v[i]) begin
                        tmp_buf[int'(packer_count) - pop_cnt + push_cnt] = in_vals[i];
                        push_cnt++;
                    end
                end
            end

            packer_buf_nxt   = tmp_buf;
            packer_count_nxt = 4'(int'(packer_count) - pop_cnt + push_cnt);
        end
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
            t_ready_o    <= 1'b0;
            wfifo_wr_ptr <= 2'd0;
            wfifo_rd_ptr <= 2'd0;
            wfifo_count  <= 3'd0;
            gbx_w0v      <= 1'b0;
            gbx_w1v      <= 1'b0;
            gbx_boff     <= 3'd0;
            s1_valid     <= 1'b0;
            s1_d1_av     <= 1'b0;  s1_d2_av <= 1'b0;
            s1_d1_bv     <= 1'b0;  s1_d2_bv <= 1'b0;
            coeff_count  <= 9'd0;
            packer_count <= 4'd0;
        end else begin
            state        <= state_nxt;

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
            coeff_count  <= coeff_count_nxt;
            packer_buf   <= packer_buf_nxt;
            packer_count <= packer_count_nxt;

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



    // synthesis translate_on

endmodule
