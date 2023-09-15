`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.09.2023 17:36:06
// Design Name: 
// Module Name: sr_latch
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

// Structural
// module sr_latch(Q, Qn, S, R);
//   output Q, Qn;
//   input S, R;

//   nand n1(Q, R, Qn);
//   nand n2(Qn, S, Q);
// endmodule

// behavioral
module sr_latch(Q, Qn, S, R);
  output Q, Qn;
  input S, R;

  wire Q1, Qn1;
  
  assign #1 Q1 = ~(S & Qn1);
  assign #1 Qn1 = ~(R & Q1);
  assign Q = Q1;
  assign Qn = Qn1;
endmodule