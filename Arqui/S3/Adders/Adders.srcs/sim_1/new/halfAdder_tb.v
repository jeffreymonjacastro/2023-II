`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 11:46:28
// Design Name: 
// Module Name: halfAdder_tb
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


module halfAdder_tb;
	reg a, b;
	wire s, c;

	halfAdder hA(s, c, a, b);

	initial begin
		a = 0; b = 0;
		#10 a = 0; b = 1;
		#10 a = 1; b = 0;
		#10 a = 1; b = 1;
		#10 $finish;
	end

	initial begin
		$monitor("%2d: | a=%b | b=%b | s=%b | c=%b", $time, a, b, s, c);
	end

endmodule
