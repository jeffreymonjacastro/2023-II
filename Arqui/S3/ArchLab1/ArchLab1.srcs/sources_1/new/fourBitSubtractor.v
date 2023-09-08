`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.09.2023 21:35:48
// Design Name: 
// Module Name: fourBitSubtractor
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


module fourBitSubtractor(output [3:0] d, output bo, input [3:0] a, b);
    wire bo1, bo2, bo3;

    fullSubtractor fS1(d[0], bo1, a[0], b[0], 1'b0);
    fullSubtractor fS2(d[1], bo2, a[1], b[1], bo1);
    fullSubtractor fS3(d[2], bo3, a[2], b[2], bo2);
    fullSubtractor fS4(d[3], bo, a[3], b[3], bo3);
endmodule
