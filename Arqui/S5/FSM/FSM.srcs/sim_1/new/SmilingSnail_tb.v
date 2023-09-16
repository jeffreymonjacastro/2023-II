`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.09.2023 09:19:35
// Design Name: 
// Module Name: SmilingSnail_tb
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


module SmilingSnail_tb();
    reg clk, reset, number;
    wire smile;

    SmilingSnail SS(clk, reset, number, smile);

    always #5 clk = ~clk;

    initial begin
        clk = 0;
        reset = 0;
        number = 0;
        
        #10 number = 1;
        #10 number = 1;
        #10 number = 0;
        #10 number = 1;
        #10 $finish;
    end
endmodule
