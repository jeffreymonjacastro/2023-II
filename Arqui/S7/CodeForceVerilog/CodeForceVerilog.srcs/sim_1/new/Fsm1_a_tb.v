`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 29.09.2023 20:22:51
// Design Name: 
// Module Name: Fsm1_a_tb
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


module Fsm1_a_tb();
    reg clk, reset, in;
    wire out;

    Fsm1_a fsm1(clk, reset, in, out);

    initial begin
        clk = 0; reset = 1; in = 1;
        #3
        reset = 0;
        #10
        in = 0;
        #40
        in = 1;
        #10 $finish;
    end

    always #5 clk = ~clk;
endmodule
