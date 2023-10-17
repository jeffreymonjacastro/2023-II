`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 13.10.2023 23:16:23
// Design Name: 
// Module Name: clk_divider
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


module clk_divider(
    input clk,
    input reset,
    output clk_en
    );

    wire [27:0] din;
    wire [27:0] clkdiv;

    dff dff_inst0 (
        .clk(clk),
        .reset(reset),
        .D(din[0]),
        .Q(clkdiv[0])
    );

    genvar i;
    generate
        for (i = 1; i < 27; i=i+1) 
            begin : dff_gen_label
                dff dff_inst (
                    .clk(clkdiv[i-1]),
                    .reset(reset),
                    .D(din[i]),
                    .Q(clkdiv[i])
                );
            end
    endgenerate;

    assign din = ~clkdiv;
 
    assign clk_en = clkdiv[26];
 
endmodule
