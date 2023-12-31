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
  reg D, En;
	wire Q, Qn;

	d_latch dlatch(Q, Qn, D, En);

	initial begin
		En = 0; D = 0;
		#100 $finish;
	end

	always #12 En = ~En;
	always #10 D = ~D;
endmodule
