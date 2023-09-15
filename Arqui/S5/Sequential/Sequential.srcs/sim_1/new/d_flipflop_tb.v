`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.09.2023 12:45:56
// Design Name: 
// Module Name: d_flipflop_tb
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

// Structural
module d_flipflop_tb();
	reg En, D;
	wire Q, Qn;

	d_flipflop dff(Q, Qn, En, D);

	initial begin
		En = 0; D = 0;
		#120 $finish;
	end

	always #10 En = ~En;
	always #13 D = ~D;

endmodule


// module d_flipflop_tb();
// 	reg clk, En, D;
// 	wire Q, Qn;

// 	d_flipflop dff(Q, Qn, clk, En, D);

// 	initial begin
// 		clk = 0; En = 0; D = 0;
// 		#120 $finish;
// 	end

// 	always #10 clk = ~clk;
// 	always #33 En = ~En;
// 	always #13 D = ~D;

// endmodule
