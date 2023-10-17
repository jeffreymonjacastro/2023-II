`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 13.10.2023 23:20:40
// Design Name: 
// Module Name: dff
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


module dff(input clk, reset, output D, Q);
    reg Q;
    always @(posedge clk, posedge reset)
    begin
        if(reset)
            Q <= 1'b0;
        else
            Q <= D;
    end
	
endmodule
