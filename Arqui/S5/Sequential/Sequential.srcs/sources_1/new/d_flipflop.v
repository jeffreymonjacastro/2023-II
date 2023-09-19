`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.09.2023 12:40:25
// Design Name: 
// Module Name: d_flipflop
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

// D Flip Flop normal using D Latch (structural);
module d_flipflop(Q, Qn, D, clk);
	input D, clk;
	output Q, Qn;

	wire n1, n2, n3;

	not(n3, clk);	

	d_latch master(n1, n2, D, n3);
	d_latch slave(Q, Qn, n1, clk);
endmodule



// D Flip Flop normal [with clock] (behavioral)
// module d_flipflop(Q, Qn, D, clk);
// 	input wire clk, D;
// 	output reg Q, Qn;

// 	always@(posedge clk) begin
// 		Q <= D;
// 		Qn <= ~D;
// 	end
// endmodule



// D Flip Flop ENABLE Synchronus [with clock] (behavioral)
// module d_flipflop(Q, Qn, clk, En, D);
// 	input wire clk, En, D;
// 	output reg Q, Qn;

// 	always@(posedge clk) begin
// 		if(En) begin
// 			Q <= D;
// 			Qn <= ~D;
// 		end
// 	end
// endmodule


// D Flip Flop ENABLE Asynchronus [with clock] (behavioral)
// module d_flipflop(Q, Qn, clk, En, D);
// 	input wire clk, En, D;
// 	output reg Q, Qn;

// 	always@(posedge clk, posedge En) begin
// 		if(En) begin
// 			Q <= D;
// 			Qn <= ~D;
// 		end
// 	end

// endmodule




