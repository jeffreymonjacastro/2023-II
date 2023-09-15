`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.09.2023 18:25:04
// Design Name: 
// Module Name: d_latch
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


module d_latch(Q, Qn, D, E);
  output Q, Qn;
  input D, E;

	wire s1, r1;

	assign s1 = ~(D & E);
	assign r1 = ~(~D & E);

	sr_latch srlatch(Q, Qn, s1, r1);
endmodule
