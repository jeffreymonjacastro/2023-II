`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 30.09.2023 02:08:02
// Design Name: 
// Module Name: visor
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


module visor(
  input pl, re, ff, st, m, clk, reset,
  output reg P, R, F
  );

reg [2:0] state, next;

// Sates
parameter S0 = 3'b000;
parameter S1 = 3'b001;
parameter S2 = 3'b010;
parameter S3 = 3'b011;
parameter S4 = 3'b100;
parameter S5 = 3'b101;
parameter S6 = 3'b110;
parameter S7 = 3'b111;

// Next state logic
always @(*) begin
  case (state)
    S0: begin
      if (pl && !re && !ff && !st) next = S1;
      else if (!pl && re & !ff && !st) next = S6;
      else if (!pl && !re && ff && !st) next = S7;
    end

    S1: begin
      if (st) next = S0;
      else if (pl && re && !ff && !st) next = S2;
      else if (pl && !re && ff && !st) next = S4;
    end

    S2: begin
      if (st) next = S0;
      else if (pl && !re && !ff && !st) next = S3;
    end

    S3: begin
      if (st) next = S0;
      else if (pl && !st && ~m) next = S1;
    end

    S4: begin
      if (st) next = S0;
      else if (pl && !re && !ff && !st) next = S5;
    end

    S5: begin
      if (st) next = S0;
      else if (pl && !st && ~m) next = S1;
    end

    S6: begin
      if (st) next = S0;
      else if (!pl && !re && !ff && !st) next = S0;
    end

    S7: begin
      if (st) next = S0;
      else if (!pl && !re && !ff && !st) next = S0;
    end
  endcase
end

// register
always @(posedge clk, posedge reset)
begin
  if (reset) state <= S0;
  else state <= next;
end

// Output logic
always @(*)
begin 
  case(state)
    S0: begin
      P=0 ;R=0; F=0;
    end
    
    S1, S2, S4: begin
      P=1; R=0; F=0;
    end
    
    S3, S6: begin
      P=0; R=1; F=0;
    end

    S5, S7: begin
      P=0; R=0; F=1;
    end
  endcase
end

endmodule