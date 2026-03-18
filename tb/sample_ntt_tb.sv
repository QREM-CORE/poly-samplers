// -----------------------------------------------------------------------------
// Author      : Salwan Aldhahab
// Module      : sample_ntt_tb
// Standard    : FIPS 203 ML-KEM — verification of Algorithm 7 (SampleNTT)
//
// Description :
//   Self-checking testbench for sample_ntt.
//
//   1. Generates a deterministic pseudo-random byte stream (input stimulus).
//   2. Runs the same rejection-sampling algorithm in software to build a
//      golden list of 256 expected 12-bit coefficients.
//   3. Drives the byte stream into the DUT over an AXI4-Stream sink.
//   4. Applies randomised output backpressure (~25 % stall rate).
//   5. Unpacks each 48-bit output beat into four 12-bit coefficients and
//      compares lane-by-lane against the golden model.
//   6. Checks t_last_o timing and t_keep_o correctness.
//   7. Reports PASS / FAIL at the end.
// -----------------------------------------------------------------------------

module sample_ntt_tb;

    // =====================================================================
    // Parameters
    // =====================================================================

    localparam int DWIDTH      = 256;           // Must match DUT
    localparam int KEEP_WIDTH  = DWIDTH / 8;    // 32 bytes per beat
    localparam int Q           = 3329;
    localparam int NUM_COEFFS  = 256;
    localparam int NUM_BYTES   = 1024;          // Enough to guarantee 256 accepted

    // =====================================================================
    // DUT signals
    // =====================================================================

    logic                      clk;
    logic                      rst;

    // Control
    logic                      start;
    logic                      done;

    // AXI4-Stream Sink (to DUT)
    logic [DWIDTH-1:0]         t_data_i;
    logic                      t_valid_i;
    logic                      t_last_i;
    logic [KEEP_WIDTH-1:0]     t_keep_i;
    logic                      t_ready_o;

    // AXI4-Stream Source (from DUT)
    logic [47:0]               t_data_o;
    logic                      t_valid_o;
    logic                      t_last_o;
    logic [5:0]                t_keep_o;
    logic                      t_ready_i;

    // =====================================================================
    // Test infrastructure
    // =====================================================================

    byte unsigned              stimulus_bytes [$];     // Input byte stream
    int unsigned               golden_coeffs  [$];     // Expected 12-bit values
    int unsigned               observed_count;
    int unsigned               error_count;
    logic                      done_seen;     // Latched version of done pulse

    // =====================================================================
    // Latch the one-cycle done pulse so the TB never misses it
    // =====================================================================

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            done_seen <= 1'b0;
        else if (done)
            done_seen <= 1'b1;
    end

    // =====================================================================
    // DUT instantiation
    // =====================================================================

    sample_ntt #(
        .DWIDTH     (DWIDTH),
        .KEEP_WIDTH (KEEP_WIDTH)
    ) dut (
        .clk        (clk),
        .rst        (rst),
        .start      (start),
        .done       (done),
        .t_data_i   (t_data_i),
        .t_valid_i  (t_valid_i),
        .t_last_i   (t_last_i),
        .t_keep_i   (t_keep_i),
        .t_ready_o  (t_ready_o),
        .t_data_o   (t_data_o),
        .t_valid_o  (t_valid_o),
        .t_last_o   (t_last_o),
        .t_keep_o   (t_keep_o),
        .t_ready_i  (t_ready_i)
    );

    // =====================================================================
    // Clock: 100 MHz (10 ns period)
    // =====================================================================

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // =====================================================================
    // Task: Generate a deterministic pseudo-random byte stream
    // =====================================================================

    task automatic generate_stimulus();
        int seed = 32'h5A1C_2026;
        stimulus_bytes.delete();
        for (int i = 0; i < NUM_BYTES; i++) begin
            stimulus_bytes.push_back($urandom(seed));
            seed += 32'h9E37;
        end
    endtask

    // =====================================================================
    // Task: Build the golden reference (software rejection sampling)
    // =====================================================================

    task automatic build_golden_model();
        int idx, d1, d2;
        golden_coeffs.delete();
        idx = 0;
        while ((idx + 2 < stimulus_bytes.size()) && (golden_coeffs.size() < NUM_COEFFS)) begin
            d1 = stimulus_bytes[idx] + ((stimulus_bytes[idx+1] & 8'h0F) << 8);
            d2 = ((stimulus_bytes[idx+1] >> 4) & 8'h0F) + (stimulus_bytes[idx+2] << 4);

            if ((d1 < Q) && (golden_coeffs.size() < NUM_COEFFS))
                golden_coeffs.push_back(d1);
            if ((d2 < Q) && (golden_coeffs.size() < NUM_COEFFS))
                golden_coeffs.push_back(d2);

            idx += 3;
        end

        if (golden_coeffs.size() != NUM_COEFFS)
            $fatal(1, "Golden model only produced %0d coeffs — increase NUM_BYTES.",
                   golden_coeffs.size());
    endtask

    // =====================================================================
    // Task: Drive input bytes into the DUT's AXI sink
    // =====================================================================

    task automatic drive_axi_sink();
        int byte_idx  = 0;
        int beat_size;

        while ((byte_idx < stimulus_bytes.size()) && !done_seen) begin
            beat_size = stimulus_bytes.size() - byte_idx;
            if (beat_size > KEEP_WIDTH) beat_size = KEEP_WIDTH;

            // Present data at negedge — stable for DUT to sample at posedge.
            @(negedge clk);
            t_data_i = '0;
            t_keep_i = '0;
            for (int lane = 0; lane < beat_size; lane++) begin
                t_data_i[8*lane +: 8] = stimulus_bytes[byte_idx + lane];
                t_keep_i[lane]        = 1'b1;
            end
            t_last_i  = ((byte_idx + beat_size) >= stimulus_bytes.size());
            t_valid_i = 1'b1;

            // Wait until DUT accepts the beat or done fires.
            @(posedge clk);
            while (!t_ready_o && !done_seen) @(posedge clk);
            if (done_seen) break;

            byte_idx += beat_size;
        end

        // Park inputs low.
        @(negedge clk);
        t_valid_i = 1'b0;
        t_last_i  = 1'b0;
        t_keep_i  = '0;
        t_data_i  = '0;
    endtask

    // =====================================================================
    // Output backpressure: ready 3 out of every 4 cycles (~75 %)
    // =====================================================================
    // Uses a simple 2-bit counter instead of $urandom_range, which
    // is unsupported in ModelSim ASE.

    logic [1:0] bp_cnt;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            t_ready_i <= 1'b0;
            bp_cnt    <= 2'd0;
        end else begin
            bp_cnt    <= bp_cnt + 2'd1;
            t_ready_i <= (bp_cnt != 2'd0);  // low 1-in-4 cycles
        end
    end

    // =====================================================================
    // Output monitor & self-checker
    // =====================================================================

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            observed_count <= 0;
            error_count    <= 0;
        end else if (t_valid_o && t_ready_i) begin

            // -- Check t_keep_o --
            if (t_keep_o != 6'h3F) begin
                $display("ERROR [beat %0d]: t_keep_o = 0x%0h, expected 0x3F",
                         observed_count / 4, t_keep_o);
                error_count <= error_count + 1;
            end

            // -- Check t_last_o timing --
            if ((observed_count == NUM_COEFFS - 4) && !t_last_o) begin
                $display("ERROR: t_last_o not asserted on final beat");
                error_count <= error_count + 1;
            end
            if ((observed_count < NUM_COEFFS - 4) && t_last_o) begin
                $display("ERROR: t_last_o asserted early at coeff index %0d", observed_count);
                error_count <= error_count + 1;
            end

            // -- Check each of the 4 coefficient lanes --
            for (int lane = 0; lane < 4; lane++) begin
                automatic int unsigned got = t_data_o[12*lane +: 12];
                automatic int unsigned idx = observed_count + lane;
                if (idx >= NUM_COEFFS) begin
                    $display("ERROR: extra coefficient on lane %0d", lane);
                    error_count <= error_count + 1;
                end else if (got !== golden_coeffs[idx][11:0]) begin
                    $display("ERROR: Coeff[%0d] mismatch — got %0d, expected %0d",
                             idx, got, golden_coeffs[idx]);
                    error_count <= error_count + 1;
                end
            end

            $display("[TB] Output beat %0d: coeffs %0d-%0d  t_last=%0b",
                     observed_count / 4, observed_count, observed_count + 3, t_last_o);
            observed_count <= observed_count + 4;
        end
    end

    // =====================================================================
    // Periodic debug: print DUT state every 500 cycles
    // =====================================================================

    int unsigned cycle_cnt;
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            cycle_cnt <= 0;
        else begin
            cycle_cnt <= cycle_cnt + 1;
            if (cycle_cnt % 500 == 0)
                $display("[DBG] cyc=%0d st=%0d wfifo=%0d coeff=%0d oq0v=%0b oq1v=%0b agg=%0d rdy=%0b val=%0b done=%0b",
                         cycle_cnt, dut.state, dut.wfifo_count, dut.coeff_count, dut.oq_valid[0], dut.oq_valid[1], dut.agg_count, t_ready_i, t_valid_o, done);
        end
    end

    // =====================================================================
    // Main test sequence
    // =====================================================================

    initial begin
        // -- Initialise --
        rst       = 1'b1;
        start     = 1'b0;
        t_data_i  = '0;
        t_valid_i = 1'b0;
        t_last_i  = 1'b0;
        t_keep_i  = '0;

        generate_stimulus();
        build_golden_model();
        $display("[TB] Golden model built: %0d coefficients from %0d bytes.",
                 golden_coeffs.size(), stimulus_bytes.size());

        // -- Release reset --
        repeat (5) @(posedge clk);
        rst = 1'b0;

        // -- Pulse start (at negedge so DUT samples cleanly at posedge) --
        @(negedge clk);
        start = 1'b1;
        @(negedge clk);
        start = 1'b0;

        // -- Drive input, then wait for done — watchdog covers both --
        fork
            begin
                drive_axi_sink();
                wait (done_seen == 1'b1);
            end
            begin : watchdog
                repeat (50_000) @(posedge clk);
                $fatal(1, "TIMEOUT: DUT did not assert done within 50 000 cycles");
            end
        join_any
        disable fork;

        @(posedge clk);

        // -- Final verdict --
        if (observed_count != NUM_COEFFS)
            $fatal(1, "FAIL: observed %0d coefficients, expected %0d",
                   observed_count, NUM_COEFFS);

        if (error_count != 0)
            $fatal(1, "FAIL: %0d mismatches detected", error_count);

        $display("PASS: sample_ntt produced %0d coefficients matching the golden model.",
                 NUM_COEFFS);
        $finish;
    end

endmodule
