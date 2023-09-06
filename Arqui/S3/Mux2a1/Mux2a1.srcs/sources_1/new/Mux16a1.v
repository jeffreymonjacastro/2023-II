`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05.09.2023 23:09:18
// Design Name: 
// Module Name: Mux16a1
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


module Mux16a1(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,s0,s1,s2,s3,y);
    input a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,s0,s1,s2,s3;
    output y;
    
    wire n1, n2;
    
    Mux8a1 mux1(a0,a1,a2,a3,a4,a5,a6,a7,s0,s1,s2,n1);
    Mux8a1 mux2(a8,a9,a10,a11,a12,a13,a14,a15,s0,s1,s2,n2);
    
    Mux2a1 mux3(n1, n2, s3, y);
endmodule
