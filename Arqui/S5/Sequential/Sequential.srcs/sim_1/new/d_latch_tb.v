`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.09.2023 18:39:37
// Design Name: 
// Module Name: d_latch_tb
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


module d_latch_tb;
  reg D, E;
	wire Q, Qn;

	d_latch dlatch(Q, Qn, D, E);

	initial begin
		D = 0; E = 1;
		#10 D = 1; E = 1;
		#10 D = 0; E = 0;
		#10 D = 1; E = 0;
		#10 $finish;
	end
endmodule
