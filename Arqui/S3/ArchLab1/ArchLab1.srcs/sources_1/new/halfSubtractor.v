`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.09.2023 20:16:00
// Design Name: 
// Module Name: halfSubtractor
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

// Behavioral
module halfSubtractor(d, bo, a, b);
	input a, b;
	output d, bo;

	assign d = a ^ b;
	assign bo = ~a & b;
endmodule

// Structural
// module halfSubtractor(d, bo, a, b);
// 	input a, b;
// 	output d, bo;
// 	wire a1;

// 	xor x1(d, a, b);
// 	not n1(a1, a);
// 	and a2(bo, a1, b);
// endmodule
