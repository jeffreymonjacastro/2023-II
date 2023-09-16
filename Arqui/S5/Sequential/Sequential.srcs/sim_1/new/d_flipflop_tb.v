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

// Normal D Flip Flop
// module d_flipflop_tb();
// 	reg En, D;
// 	wire Q, Qn;

// 	d_flipflop dff(Q, Qn, En, D);

// 	initial begin
// 		En = 0; D = 0;
// 		#120 $finish;
// 	end

// 	always #10 En = ~En;
// 	always #13 D = ~D;

// endmodule


// D Flip Flop with synchronus clock
module d_flipflop_tb();
	reg clk, D;
	wire Q, Qn;

	d_flipflop dff(Q, Qn, D, clk);

	initial begin
		clk = 0; D = 0;
		#120 $finish;
	end

	always #10 clk = ~clk;
	always #13 D = ~D;

endmodule
