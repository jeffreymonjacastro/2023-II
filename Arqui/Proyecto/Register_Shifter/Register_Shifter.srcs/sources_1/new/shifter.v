`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.11.2023 19:52:04
// Design Name: 
// Module Name: shifter
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
module clk_divider (
    input clk,
    input reset,
    output reg clk_div
    );

    reg [3:0] counter = 0;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 0;
            clk_div <= 0;
        end
        else begin
            counter <= counter + 1;
            if (counter == 50) begin
                counter <= 0;
                clk_div <= ~clk_div;
            end
        end
    end
endmodule


module shifter (
  input wire clk,           // Reloj
  input wire rst,           // Reset
  input wire [7:0] data,    //bits 11-4
  input wire [7:0] data_in, // Datos de entrada
  output reg [7:0] q        // Salida del shift register
);
  integer width_;
  integer i;
  
  wire clk_div;
  
  clk_divider clk_d(clk, reset, clk_div);
  
  always @* begin
    width_ = 0;
    for (i = 3 ; i <= 7 ; i = i + 1)begin
      if (data[i] == 1) begin
        width_ = width_ + (2 ** (i-3));
      end
    end
  end
  
  always @(posedge clk_div or posedge rst) begin
    if (rst) begin
      q <= 8'b0;  // Reset del registro
    end else begin
      // Realizar operaciones según el control de entrada
      casex (data[2:1])
        2'b00: begin
          q <= q << width_; // Shift left LSL
        end
        2'b01: begin
          q <= q >> width_; // Shift right LSR
        end
        2'b11: q <= data_in; // Load
        default: ; // No hace nada para 2'b00
      endcase
    end
  end

endmodule

