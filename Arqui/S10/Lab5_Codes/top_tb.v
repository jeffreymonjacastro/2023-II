`timescale 1ns / 1ps

module top_tb;
  reg clk;
	reg reset;
	wire [31:0] WriteData;
	wire [31:0] DataAdr;
	wire MemWrite;

  top dut(
		.clk(clk),
		.reset(reset),
		.WriteData(WriteData),
		.DataAdr(DataAdr),
		.MemWrite(MemWrite)
	);

  initial begin
    $dumpfile("top_tb.vcd");
    $dumpvars(0, top_tb);

    clk = 0;
    reset = 1;
    #6;
    reset = 0;
    #300;
    $finish;
  end

  always #5 clk = ~clk;

  // always @(negedge clk) begin
	// 	if (MemWrite) begin
	// 		if ((DataAdr === 100) & (WriteData === 7)) begin
	// 			$display("Simulation succeeded");
	// 			$finish;
	// 		end
	// 		else if (DataAdr !== 96) begin
	// 			$display("Simulation failed");
	// 			$finish;
	// 		end
  //   end
  // end

  initial begin
    $monitor("%2d: | clk = %b | reset = %b | DataAdr = %b | WriteData = %b | MemWrite = %b", $time, clk, reset, DataAdr, WriteData, MemWrite);
  end

endmodule