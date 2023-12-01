`timescale 1ns / 1ps
module controller_tb;
	reg clk;
	reg reset;
	wire [31:0] WriteData;
	wire [31:0] DataAdr;
	wire MemWrite;

	top dut(
		.clk(clk),
		.reset(reset),
		.WriteData(WriteData),
		.Adr(DataAdr),
		.MemWrite(MemWrite)
	);
	initial begin
        $dumpfile("multi_tb.vcd");
        $dumpvars(0, controller_tb);
		reset <= 1;
		#(22)
			;
		reset <= 0;
	end
	always begin
		clk <= 1;
		#(5)
			;
		clk <= 0;
		#(5)
			;
	end
	always @(negedge clk)

			if ((DataAdr === 32'hb8)) begin
				$display("Final de simulacion");
				$stop;
			end

endmodule
