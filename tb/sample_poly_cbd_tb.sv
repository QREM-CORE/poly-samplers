// -----------------------------------------------------------------------------
// Author      : Salwan Aldhahab
// Module      : sample_poly_cbd_tb
// Standard    : FIPS 203 ML-KEM — verification of Algorithm 8 (SamplePolyCBD)
//
// Description :
//   Self-checking testbench for the unified sample_poly_cbd module.
//
//   1. Dynamically tests both η=2 (ML-KEM-512) and η=3 (ML-KEM-768/1024).
//   2. Generates a deterministic pseudo-random byte stream.
//   3. Builds a software-based golden reference for the current η.
//   4. Drives the AXI4-Stream sink and applies 75% output backpressure.
//   5. Checks cycle-accurate handshakes and validates all 256 coefficients.
// -----------------------------------------------------------------------------

module sample_poly_cbd_tb;

    // =====================================================================
    // Parameters & Variables
    // =====================================================================

    localparam int DWIDTH       = 256;            // Must match DUT
    localparam int KEEP_WIDTH   = DWIDTH / 8;     // 32 bytes per beat
    localparam int Q            = 3329;
    localparam int NUM_COEFFS   = 256;

    // Dynamically controlled by the test sequence
    int unsigned current_eta;
    logic        is_eta3;

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
    logic                      done_seen;              // Latched done pulse

    // Latch the one-cycle done pulse
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            done_seen <= 1'b0;
        else if (done)
            done_seen <= 1'b1;
    end

    // =====================================================================
    // DUT instantiation
    // =====================================================================

    sample_poly_cbd #(
        .DWIDTH     (DWIDTH),
        .KEEP_WIDTH (KEEP_WIDTH)
    ) dut (
        .clk        (clk),
        .rst        (rst),
        .start      (start),
        .is_eta3    (is_eta3),   // <-- Runtime Control Signal
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
        int unsigned seed = 32'hCBD0_2026;
        stimulus_bytes.delete();
        // Generate enough bytes based on the CURRENT eta
        for (int i = 0; i < (64 * current_eta); i++) begin
            stimulus_bytes.push_back($urandom(seed));
            seed += 32'h9E37;
        end
    endtask

    // =====================================================================
    // Task: Build the golden reference (software CBD sampling)
    // =====================================================================

    task automatic build_golden_model();
        int bit_idx;
        int x_val, y_val;
        int coeff;
        golden_coeffs.delete();

        for (int i = 0; i < NUM_COEFFS; i++) begin
            x_val = 0;
            y_val = 0;

            // x ← Σ_{j=0}^{η-1} b[2ηi + j]
            for (int j = 0; j < current_eta; j++) begin
                bit_idx = 2 * current_eta * i + j;
                x_val += (stimulus_bytes[bit_idx / 8] >> (bit_idx % 8)) & 1;
            end

            // y ← Σ_{j=0}^{η-1} b[2ηi + η + j]
            for (int j = 0; j < current_eta; j++) begin
                bit_idx = 2 * current_eta * i + current_eta + j;
                y_val += (stimulus_bytes[bit_idx / 8] >> (bit_idx % 8)) & 1;
            end

            // f[i] ← (x − y) mod q
            if (x_val >= y_val)
                coeff = x_val - y_val;
            else
                coeff = Q - (y_val - x_val);

            golden_coeffs.push_back(coeff);
        end
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

            @(negedge clk);
            t_data_i = '0;
            t_keep_i = '0;
            for (int lane = 0; lane < beat_size; lane++) begin
                t_data_i[8*lane +: 8] = stimulus_bytes[byte_idx + lane];
                t_keep_i[lane]        = 1'b1;
            end
            t_last_i  = ((byte_idx + beat_size) >= stimulus_bytes.size());
            t_valid_i = 1'b1;

            @(posedge clk);
            while (!t_ready_o && !done_seen) @(posedge clk);
            if (done_seen) break;

            byte_idx += beat_size;
        end

        @(negedge clk);
        t_valid_i = 1'b0;
    endtask

    // =====================================================================
    // Output backpressure: ready 3 out of every 4 cycles (~75 %)
    // =====================================================================

    logic [1:0] bp_cnt;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            t_ready_i <= 1'b0;
            bp_cnt    <= 2'd0;
        end else begin
            bp_cnt    <= bp_cnt + 2'd1;
            t_ready_i <= (bp_cnt != 2'd0);
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

            if (t_keep_o != 6'h3F) begin
                $display("ERROR [beat %0d]: t_keep_o = 0x%0h, expected 0x3F", observed_count / 4, t_keep_o);
                error_count <= error_count + 1;
            end

            if ((observed_count == NUM_COEFFS - 4) && !t_last_o) begin
                $display("ERROR: t_last_o not asserted on final beat");
                error_count <= error_count + 1;
            end
            if ((observed_count < NUM_COEFFS - 4) && t_last_o) begin
                $display("ERROR: t_last_o asserted early at coeff index %0d", observed_count);
                error_count <= error_count + 1;
            end

            for (int lane = 0; lane < 4; lane++) begin
                automatic int unsigned got = t_data_o[12*lane +: 12];
                automatic int unsigned idx = observed_count + lane;
                if (idx >= NUM_COEFFS) begin
                    $display("ERROR: extra coefficient on lane %0d", lane);
                    error_count <= error_count + 1;
                end else if (got !== golden_coeffs[idx][11:0]) begin
                    $display("ERROR: Coeff[%0d] mismatch — got %0d, expected %0d", idx, got, golden_coeffs[idx]);
                    error_count <= error_count + 1;
                end
            end
            observed_count <= observed_count + 4;
        end
    end

    // =====================================================================
    // Periodic debug
    // =====================================================================

    int unsigned cycle_cnt;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) cycle_cnt <= 0;
        else begin
            cycle_cnt <= cycle_cnt + 1;
            if (cycle_cnt % 500 == 0)
                $display("[DBG] cyc=%0d st=%0d wfifo=%0d coeff=%0d oq0v=%0b oq1v=%0b rdy=%0b val=%0b done=%0b",
                         cycle_cnt, dut.state, dut.wfifo_count, dut.coeff_count, dut.oq_valid[0], dut.oq_valid[1], t_ready_i, t_valid_o, done);
        end
    end

    // =====================================================================
    // Main test sequence: Run BOTH Modes!
    // =====================================================================

    initial begin
        $display("==========================================================");
        $display("Starting Unified sample_poly_cbd Testbench");
        $display("==========================================================");

        // Run Test 1: ML-KEM-512 Configuration
        run_test_case(2);

        // Run Test 2: ML-KEM-768/1024 Configuration
        run_test_case(3);

        $display("==========================================================");
        $display("ALL TESTS PASSED: Both ETA=2 and ETA=3 modes verified!");
        $display("==========================================================");
        $finish;
    end

    // Reusable task to run the full simulation flow for a given ETA
    task automatic run_test_case(int eta_val);
        current_eta = eta_val;
        is_eta3     = (eta_val == 3) ? 1'b1 : 1'b0;

        // -- Initialize & Reset --
        rst       = 1'b1;
        start     = 1'b0;
        t_data_i  = '0;
        t_valid_i = 1'b0;
        t_last_i  = 1'b0;
        t_keep_i  = '0;

        generate_stimulus();
        build_golden_model();

        $display("\n[TB] -----------------------------------------------------");
        $display("[TB] Testing ETA=%0d. Golden model: %0d coeffs from %0d bytes.",
                 current_eta, golden_coeffs.size(), stimulus_bytes.size());

        // -- Release reset --
        repeat (5) @(posedge clk);
        rst = 1'b0;

        // -- Pulse start --
        @(negedge clk);
        start = 1'b1;
        @(negedge clk);
        start = 1'b0;

        // -- Drive input and wait --
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

        // -- Evaluate --
        if (observed_count != NUM_COEFFS)
            $fatal(1, "FAIL ETA=%0d: observed %0d coefficients, expected %0d", current_eta, observed_count, NUM_COEFFS);

        if (error_count != 0)
            $fatal(1, "FAIL ETA=%0d: %0d mismatches detected", current_eta, error_count);

        $display("[TB] PASS: sample_poly_cbd perfectly matched golden model for ETA=%0d.", current_eta);
    endtask

endmodule
