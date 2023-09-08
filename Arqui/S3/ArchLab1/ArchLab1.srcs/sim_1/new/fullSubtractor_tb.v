`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 07.09.2023 21:13:38
// Design Name: 
// Module Name: fullSubtractor_tb
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


module fullSubtractor_tb;
  reg a, b, bi;
  wire d, bo;

  fullSubtractor fS(d, bo, a, b, bi);

  initial begin
    a = 1'b0;
    b = 1'b0;
    bi = 1'b0;
    #40 $finish;
  end

  always #20 a = ~a;
  always #10 b = ~b;	
  always #5 bi = ~bi;

endmodule
