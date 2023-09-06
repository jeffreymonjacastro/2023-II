`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 12:05:18
// Design Name: 
// Module Name: fullAdder_tb
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


module fullAdder_tb;
  reg a, b, ci;
  wire s, co;

  fullAdder fA(s, co, a, b, ci);

  initial begin
    a = 1'b0;
    b = 1'b0;
    ci = 1'b0;
    #80 $finish;
  end

  always #40 a = ~a;
  always #20 b = ~b;
  always #10 ci = ~ci;

  initial begin
    $monitor("%2d: | a=%b | b=%b | ci=%b | s=%b | co=%b", $time, a, b, ci, s, co);
  end

endmodule
