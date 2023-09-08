`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.09.2023 21:41:29
// Design Name: 
// Module Name: fourBitSubtractor_tb
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


module fourBitSubtractor_tb;
  reg [3:0] a, b;
  wire [3:0] d;
  wire bo;

  fourBitSubtractor fbS(d, bo, a, b);

  initial begin
    a = 4'b0101;
    b = 4'b0001;
    #10
    a = 4'b0111;
    b = 4'b0100;
    #10 $finish;
  end

endmodule
