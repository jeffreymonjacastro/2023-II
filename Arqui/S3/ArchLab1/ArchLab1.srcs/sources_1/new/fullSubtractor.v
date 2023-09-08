`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.09.2023 21:07:28
// Design Name: 
// Module Name: fullSubtractor
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


module fullSubtractor(d, bo, a, b, bi);
    input a, b, bi;
    output d, bo;

    wire d1, bo1, bo2;

    halfSubtractor hS1(d1, bo1, a, b);
    halfSubtractor hS2(d, bo2, d1, bi);

    assign bo = bo1 | bo2;
endmodule
