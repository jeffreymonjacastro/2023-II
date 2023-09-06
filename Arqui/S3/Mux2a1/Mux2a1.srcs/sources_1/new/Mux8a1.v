`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05.09.2023 23:05:53
// Design Name: 
// Module Name: Mux8a1
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

module Mux8a1(a0,a1,a2,a3,a4,a5,a6,a7,s0,s1,s2,y);
    input a0,a1,a2,a3,a4,a5,a6,a7,s0,s1,s2;
    output y;
    wire n1, n2;

    Mux4a1 mux1(a0, a1, a2, a3, s0, s1, n1);
    Mux4a1 mux2(a4, a5, a6, a7, s0, s1, n2);
    
    Mux2a1 mux3(n1, n2, s2, y);
endmodule

