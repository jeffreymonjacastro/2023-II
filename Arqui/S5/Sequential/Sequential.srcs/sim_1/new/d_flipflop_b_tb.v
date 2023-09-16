`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.09.2023 10:58:09
// Design Name: 
// Module Name: d_flipflop_b_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module d_flipflop_b_tb();
	reg clk, D;
	wire Q, Qn;

	d_flipflop_b dff(Q, Qn, D, clk);

	initial begin
		clk = 0; D = 0;
		#120 $finish;
	end

	always #10 clk = ~clk;
	always #13 D = ~D;

endmodule
