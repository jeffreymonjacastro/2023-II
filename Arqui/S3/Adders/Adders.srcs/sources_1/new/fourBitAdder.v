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


module fourBitAdder(s0, s1, s2, s3, co, a0, a1, a2, a3, b0, b1, b2, b3, cin);
	input a0, a1, a2, a3, b0, b1, b2, b3, cin;
	output s0, s1, s2, s3, co;

	wire c1, c2, c3;

	fullAdder fA1(s0, c1, a0, b0, cin);
	fullAdder fA2(s1, c2, a1, b1, c1);
	fullAdder fA3(s2, c3, a2, b2, c2);
	fullAdder fA4(s3, co, a3, b3, c3);
endmodule	
