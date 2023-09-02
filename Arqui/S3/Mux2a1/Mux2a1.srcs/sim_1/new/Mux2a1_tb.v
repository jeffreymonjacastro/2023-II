`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02.09.2023 10:33:04
// Design Name: 
// Module Name: Mux2a1_tb
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


module Mux2a1_tb;

    reg d0, d1, s;
    wire y;

    Mux2a1 test(.a0(d0), .a1(d1), .s(s), .y(y));

    initial begin
        $dumpfile("Mux2a1_tb.vcd"); // Archivo de simulacion para verlo en gtkwave
        $dumpvars(0, Mux2a1_tb); 

        d0 = 1'b0;
        d1 = 1'b0;
        s = 1'b0;
        #80 $finish;
    end

    always #40 d0 = ~d0;
    always #20 d1 = ~d1;
    always #10 s = ~s;

    initial begin
        // El monitor es para escribir en consola los valores de las variables
        $monitor("%2d:\ta=%b\tb=%b\ts=%b\ty=%b", $time, d0, d1, s, y);
    end

endmodule
