`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.09.2023 08:53:52
// Design Name: 
// Module Name: fourBitRegister_tb
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


module fourBitRegister_tb();
    reg clk;
    reg [3:0] D;
    wire [3:0] Q;

    fourBitRegister fBR(Q, D, clk);

    always begin
        #5 clk = ~clk; 
    end

    initial begin
        clk = 0; 
        D = 4'b0000; 
        #10 D = 4'b0001;
        #10 D = 4'b0010;
        #10 D = 4'b0100;
        #10 D = 4'b1000;
        #15 $finish; 
    end
endmodule
