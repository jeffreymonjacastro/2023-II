`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 30.09.2023 11:14:31
// Design Name: 
// Module Name: visor_tb
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


module visor_tb();
    reg pl, re, ff, st, m, clk, reset;
    wire P, R, F;

    visorVR visor(pl, re, ff, st, m, clk, reset, P, R, F);

    always begin
        #5 clk = ~clk; 
    end

    initial begin
        clk = 0; pl = 0; re = 0; ff = 0; st = 0; m = 1; reset = 1;
        #3
        reset = 0;
        #10
        pl = 1; re = 0; ff = 0; st = 0;
        #10
        pl = 1; re = 1; ff = 0; st = 0;
        #10
        pl = 1; re = 0; ff = 0; st = 0;
        #10
        pl = 1; st = 0; m = 0;
        #10 $finish; 
    end

endmodule
