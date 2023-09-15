`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.09.2023 13:46:46
// Design Name: 
// Module Name: mux2a1
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


module mux2a1(y, a0, a1, s);
	input a0, a1, s;
	output y;

	assign y = a0 & ~s | a1 & s;
endmodule
