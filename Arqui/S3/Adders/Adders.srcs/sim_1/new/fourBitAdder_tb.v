`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 12:33:18
// Design Name: 
// Module Name: fourBitAdder_tb
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


module fourBitAdder_tb;
  wire [3:0] s;
  wire co;
  reg [3:0] a, b;

  integer i, j;

  fourBitAdder fbA(s, co, a, b);

  initial begin
    // a = 4'b0000;
    // b = 4'b0000;
    // i = 0;
    // j = 0;

    // for(i=0; i<4; i=i+1) begin
    //   #4 
    //   a = i;
    //   for(j=0; j<4; j=j+1) begin
    //     #1
    //     b = j;
    //   end
    //   //$display("a = %b, b = %b, s = %b, co = %b", a, b, s, co);
    // end

    // $finish;

    a = 4'b0111;
    b = 4'b0001;
    #10
    a = 4'b1111;
    b = 4'b0001;
    #10 $finish;


  end
endmodule
