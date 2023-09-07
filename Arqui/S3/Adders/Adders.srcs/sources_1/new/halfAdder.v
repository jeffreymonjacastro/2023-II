`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06.09.2023 11:44:17
// Design Name: 
// Module Name: halfAdder
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


module halfAdder(s, c, a, b);
  input a, b;
  output s, c;
  
  assign s = a ^ b; // XOR
  assign c = a & b; // AND
endmodule

// module halfAdder(output s,c, input a,b);

//   XOR(s,a,b);
//   AND(c,a,b);
// endmodule
