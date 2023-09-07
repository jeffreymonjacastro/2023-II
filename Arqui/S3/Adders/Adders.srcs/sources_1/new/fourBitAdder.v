`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 12:27:34
// Design Name: 
// Module Name: fourBitAdder
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


module fourBitAdder(output [3:0] s, output co, input [3:0] a, b);
	wire c1, c2, c3;

	fullAdder fA1(s[0], c1, a[0], b[0], 1'b0);
	fullAdder fA2(s[1], c2, a[1], b[1], c1);
	fullAdder fA3(s[2], c3, a[2], b[2], c2);
	fullAdder fA4(s[3], co, a[3], b[3], c3);

endmodule	
