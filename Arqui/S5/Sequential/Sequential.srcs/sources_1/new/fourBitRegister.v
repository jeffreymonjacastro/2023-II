`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.09.2023 08:46:13
// Design Name: 
// Module Name: fourBitRegister
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


module fourBitRegister(output [3:0] Q, input wire [3:0] D, input clk);
    wire Qn0, Qn1, Qn2, Qn3;
    
    d_flipflop dff1(Q[0], Qn0, D[0], clk);
    d_flipflop dff2(Q[1], Qn1, D[1], clk);
    d_flipflop dff3(Q[2], Qn2, D[2], clk);
    d_flipflop dff4(Q[3], Qn3, D[3], clk);
endmodule
