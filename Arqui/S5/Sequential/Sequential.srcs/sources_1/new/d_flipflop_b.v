`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.09.2023 10:56:07
// Design Name: 
// Module Name: d_flipflop_b
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

// D Flip Flop normal [with clock] (behavioral)
module d_flipflop_b(Q, Qn, D, clk);
	input wire clk, D;
	output reg Q, Qn;

	always@(posedge clk) begin
		Q <= D;
		Qn <= ~D;
	end
endmodule
