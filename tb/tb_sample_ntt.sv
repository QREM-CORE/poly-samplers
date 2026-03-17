module tb_sample_ntt;

	localparam int DWIDTH      = 256;
	localparam int KEEP_WIDTH  = DWIDTH / 8;
	localparam int Q           = 3329;
	localparam int TARGET_COEF = 256;
	localparam int NUM_BYTES   = 1024;

	logic clk;
	logic rst;

	logic start;
	logic done;

	logic [DWIDTH-1:0]     t_data_i;
	logic                  t_valid_i;
	logic                  t_last_i;
	logic [KEEP_WIDTH-1:0] t_keep_i;
	logic                  t_ready_o;

	logic [15:0] t_data_o;
	logic        t_valid_o;
	logic        t_last_o;
	logic [1:0]  t_keep_o;
	logic        t_ready_i;

	byte unsigned in_bytes[$];
	int unsigned  expected_coeffs[$];
	int unsigned  observed_count;
	int unsigned  error_count;

	sample_ntt #(
		.DWIDTH(DWIDTH),
		.KEEP_WIDTH(KEEP_WIDTH)
	) dut (
		.clk(clk),
		.rst(rst),
		.start(start),
		.done(done),
		.t_data_i(t_data_i),
		.t_valid_i(t_valid_i),
		.t_last_i(t_last_i),
		.t_keep_i(t_keep_i),
		.t_ready_o(t_ready_o),
		.t_data_o(t_data_o),
		.t_valid_o(t_valid_o),
		.t_last_o(t_last_o),
		.t_keep_o(t_keep_o),
		.t_ready_i(t_ready_i)
	);

	// 100MHz clock
	initial clk = 1'b0;
	always #5 clk = ~clk;

	task automatic build_input_stream();
		int i;
		int seed;
		begin
			seed = 32'h5A1C_2026;
			in_bytes.delete();
			for (i = 0; i < NUM_BYTES; i++) begin
				in_bytes.push_back($urandom(seed));
				seed = seed + 32'h9E37;
			end
		end
	endtask

	task automatic build_golden();
		int i;
		int d1;
		int d2;
		begin
			expected_coeffs.delete();
			i = 0;
			while ((i + 2 < in_bytes.size()) && (expected_coeffs.size() < TARGET_COEF)) begin
				d1 = in_bytes[i] + ((in_bytes[i+1] & 8'h0F) << 8);
				d2 = ((in_bytes[i+1] >> 4) & 8'h0F) + (in_bytes[i+2] << 4);

				if ((d1 < Q) && (expected_coeffs.size() < TARGET_COEF)) begin
					expected_coeffs.push_back(d1);
				end

				if ((d2 < Q) && (expected_coeffs.size() < TARGET_COEF)) begin
					expected_coeffs.push_back(d2);
				end

				i = i + 3;
			end

			if (expected_coeffs.size() != TARGET_COEF) begin
				$fatal(1, "Golden model produced %0d coeffs, expected %0d. Increase NUM_BYTES.",
					   expected_coeffs.size(), TARGET_COEF);
			end
		end
	endtask

	task automatic drive_input();
		int idx;
		int beat_bytes;
		int lane;
		begin
			idx      = 0;
			t_data_i = '0;
			t_keep_i = '0;
			t_last_i = 1'b0;
			t_valid_i = 1'b0;

			while ((idx < in_bytes.size()) && !done) begin
				@(posedge clk);

				if (!t_valid_i) begin
					beat_bytes = in_bytes.size() - idx;
					if (beat_bytes > KEEP_WIDTH) beat_bytes = KEEP_WIDTH;

					t_data_i = '0;
					t_keep_i = '0;
					for (lane = 0; lane < beat_bytes; lane++) begin
						t_data_i[8*lane +: 8] = in_bytes[idx + lane];
						t_keep_i[lane] = 1'b1;
					end

					t_last_i  = ((idx + beat_bytes) >= in_bytes.size());
					t_valid_i = 1'b1;
				end

				if (t_valid_i && t_ready_o) begin
					idx = idx + beat_bytes;
					t_valid_i = 1'b0;
					t_last_i  = 1'b0;
					t_keep_i  = '0;
					t_data_i  = '0;
				end
			end

			@(posedge clk);
			t_valid_i = 1'b0;
			t_last_i  = 1'b0;
			t_keep_i  = '0;
			t_data_i  = '0;
		end
	endtask

	// Output backpressure generator
	always_ff @(posedge clk or posedge rst) begin
		if (rst) begin
			t_ready_i <= 1'b0;
		end else begin
			// Keep output mostly ready while still exercising skid behavior.
			t_ready_i <= ($urandom_range(0, 3) != 0);
		end
	end

	// Output monitor and checker
	always_ff @(posedge clk or posedge rst) begin
		int unsigned expected;
		if (rst) begin
			observed_count <= 0;
			error_count    <= 0;
		end else begin
			if (t_valid_o && t_ready_i) begin
				if (observed_count >= TARGET_COEF) begin
					error_count <= error_count + 1;
					$display("ERROR: Observed extra coefficient %0d", t_data_o);
				end else begin
					expected = expected_coeffs[observed_count];
					if (t_data_o !== expected[15:0]) begin
						error_count <= error_count + 1;
						$display("ERROR: Coeff[%0d] mismatch: got=%0d expected=%0d",
								 observed_count, t_data_o, expected);
					end

					if ((observed_count == TARGET_COEF - 1) && !t_last_o) begin
						error_count <= error_count + 1;
						$display("ERROR: t_last_o was not asserted on final coefficient");
					end

					if ((observed_count < TARGET_COEF - 1) && t_last_o) begin
						error_count <= error_count + 1;
						$display("ERROR: t_last_o asserted early at coefficient %0d", observed_count);
					end
				end

				observed_count <= observed_count + 1;
			end
		end
	end

	initial begin
		rst        = 1'b1;
		start      = 1'b0;
		t_data_i   = '0;
		t_valid_i  = 1'b0;
		t_last_i   = 1'b0;
		t_keep_i   = '0;

		build_input_stream();
		build_golden();

		repeat (5) @(posedge clk);
		rst = 1'b0;

		@(posedge clk);
		start = 1'b1;
		@(posedge clk);
		start = 1'b0;

		fork
			drive_input();
			begin : timeout_watchdog
				repeat (20000) @(posedge clk);
				$fatal(1, "Timeout waiting for done");
			end
		join_any
		disable fork;

		wait(done == 1'b1);
		@(posedge clk);

		if (observed_count != TARGET_COEF) begin
			$fatal(1, "Observed %0d coefficients, expected %0d", observed_count, TARGET_COEF);
		end

		if (error_count != 0) begin
			$fatal(1, "Test failed with %0d mismatches", error_count);
		end

		$display("PASS: sample_ntt produced %0d valid coefficients and matched golden model.", TARGET_COEF);
		$finish;
	end

endmodule