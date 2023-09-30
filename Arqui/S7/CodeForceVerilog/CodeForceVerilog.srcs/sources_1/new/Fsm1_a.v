`timescale 1ns / 1ps

module Fsm1_a(
    input clk,
    input areset,    // Asynchronous reset to state B
    input in,
    output out);    // Output 

    parameter A = 0, B = 1; 
    reg state, next_state;

    always @(*) begin    // This is a combinational always block
        // State transition logic
        next_state = state;
        case (state)
            A: if (in) next_state = A;
                else next_state = B;
            B: if (in) next_state = B;
                else next_state = A;
            default: next_state = B;
        endcase
    end

    always @(posedge clk, posedge areset) begin    // This is a sequential always block
        // State flip-flops with asynchronous reset
        if (areset) state <= B;
        else state <= next_state;
    end

    // Output logic
    // assign out = (state == ...);
	assign out = (state == B);
endmodule
