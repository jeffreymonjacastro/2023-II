`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 12:33:18
// Design Name: 
// Module Name: fourBitAdder_tb
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


module fourBitAdder_tb;
  reg a0, a1, a2, a3, b0, b1, b2, b3, cin;
	wire s0, s1, s2, s3, co;

  fourBitAdder fbA(s0, s1, s2, s3, co, a0, a1, a2, a3, b0, b1, b2, b3, cin);

  initial begin
    a0 = 0; a1 = 1; a2 = 0; a3 = 0;
    b0 = 1; b1 = 1; b2 = 0; b3 = 0;
    cin = 0;
    #10
    a0 = 1; a1 = 0; a2 = 0; a3 = 0;
    b0 = 1; b1 = 1; b2 = 1; b3 = 0;
    #10
    a0 = 1; a1 = 0; a2 = 1; a3 = 0;
    b0 = 0; b1 = 1; b2 = 0; b3 = 1;
    #10
    a0 = 1; a1 = 1; a2 = 1; a3 = 1;
    b0 = 1; b1 = 0; b2 = 0; b3 = 0;
    #10 $finish;
  end
endmodule
