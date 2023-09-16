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

//D Latch using SR Latch (behavioral)
// module d_latch(Q, Qn, D, E);
//   output Q, Qn;
//   input D, E;

// 	wire s1, r1;

// 	assign s1 = ~(D & E);
// 	assign r1 = ~(~D & E);

// 	sr_latch srlatch(Q, Qn, s1, r1);
// endmodule

// //D Latch using SR Latch (structural)
module d_latch(Q, Qn, D, En);
  output Q, Qn;
  input D, En;
	wire s1, r1;

	nand(r1, D, En);
	nand(s1, ~D, En);

	sr_latch srlatch(Q, Qn, s1, r1);
endmodule

// D Latch structural
// module d_latch(Q, Qn, D, En);
//   input D, En;
//   output Q, Qn;
// 	wire S, R;

// 	nand n1(S, D, En);
// 	nand n2(R, ~D, En);

// 	nand n3(Q, S, Qn);
// 	nand n4(Qn, R, Q);
// endmodule

// D Latch behavioral
// module d_latch(Q, Qn, D, En);
//   input wire D, En;
// 	output reg Q, Qn;

// 	always@(En, D) begin // Lista de sensibilidad
// 		if(En == 1'b1) begin
// 			Q <= D;
// 			Qn <= ~D;
// 		end
// 	end
// endmodule