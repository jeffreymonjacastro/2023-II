`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02.09.2023 10:18:04
// Design Name: 
// Module Name: Mux2a1
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


module Mux2a1(a0,a1,s,y);
    input a0, a1, s;
    output y;
    reg y; // va a poder modificarse

    always @(s or a0 or a1) begin
        // Como un ifelse, 
            // cuando s es 0 y es a0
            // cuando s es 1 y es a1
        case (s)
            1'b0: y = a0;
            1'b1: y = a1;
        endcase
    end
endmodule

/*
module Mux2a1(a0,a1,s,y);
    input a0, a1, s;
    output y;
    reg y;

    always @(s or a0 or a1) begin
        case (s)
            1'b1: y = a1;
            default: y = a0;
        endcase
    end
endmodule
*/