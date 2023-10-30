`timescale 1ns / 1ps

module testbench;
	reg clk;
	reg reset;
	wire [31:0] WriteData;
	wire [31:0] DataAdr;
	wire MemWrite;

	// Modulo top que llamará al arm
	top dut(
		.clk(clk),
		.reset(reset),
		.WriteData(WriteData),
		.DataAdr(DataAdr),
		.MemWrite(MemWrite)
	);

	initial begin
		$dumpfile("testbench.vcd");
    $dumpvars(0, testbench);
		reset <= 1;
		#22;
		reset <= 0;
	end

	always begin
		clk <= 1;
		#5;
		clk <= 0;
		#5;
	end
	
	always @(negedge clk)
		if (MemWrite)
			if ((DataAdr === 100) & (WriteData === 7)) begin
				$display("Simulation succeeded");
				$finish;
			end
			else if (DataAdr !== 96) begin
				$display("Simulation failed");
				$finish;
			end
endmodule
