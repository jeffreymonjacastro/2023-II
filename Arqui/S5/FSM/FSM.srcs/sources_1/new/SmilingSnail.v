`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 16.09.2023 09:16:30
// Design Name: 
// Module Name: SmilingSnail
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


module SmilingSnail(
    input clk,
    input reset,
    input number,
    output smile);

    reg [1:0] state, nextstate;

    parameter S0 = 2'b00;
    parameter S1 = 2'b01;
    parameter S2 = 2'b10;
    parameter S3 = 2'b11;

    // state register
    always @ (posedge clk, posedge reset)
        if (reset) state <= S0;
        else state <= nextstate;

    always @ (*) // next state logic
        case (state)
            S0: if (number)
                    nextstate = S1;
                else nextstate = S0;
            S1: if (number)
                    nextstate = S2;
                else nextstate = S0;
            S2: if (number)
                    nextstate = S2;
                else nextstate = S3;
            S3: if (number)
                    nextstate = S1;
                else nextstate = S0;
            default: nextstate = S0;
        endcase

    // output logic
    assign smile = (number & state == S3);
endmodule
