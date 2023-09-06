`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 12:02:16
// Design Name: 
// Module Name: fullAdder
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


module fullAdder(s, co, a, b, ci);
  input a, b, ci;
  output s, co;

  wire s1, c1, c2;

  // Two Half Adders
  halfAdder hA1(s1, c1, a, b);
  halfAdder hA2(s, c2, s1, ci);

  assign co = c1 | c2;

endmodule
