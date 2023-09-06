`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05.09.2023 22:58:33
// Design Name: 
// Module Name: Mux4a1
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


module Mux4a1(a0, a1, a2, a3, s0, s1, y);
    input a0, a1, a2, a3, s0, s1;
    output y;
    
    wire n1, n2;
    
    Mux2a1 mux1(a0, a1, s0, n1);
    Mux2a1 mux2(a2, a3, s0, n2);
    
    Mux2a1 mux3(n1, n2, s1, y);

endmodule
