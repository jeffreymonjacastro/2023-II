`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05.09.2023 23:13:30
// Design Name: 
// Module Name: Mux16a1_tb
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


module Mux16a1_tb;
    reg a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10 ,a11,a12,a13,a14,a15,s0,s1,s2,s3;
    reg [3:0] s;
    wire y;
    integer i;
    
    Mux16a1 test(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,s0,s1,s2,s3,y);
    
    initial begin
        s = 4'b0000;
        s0 = s[0];
        s1 = s[1];
        s2 = s[2];
        s3 = s[3];
        a0=1;a1=0;a2=0;a3=0;a4=0;a5=0;a6=0;a7=0;
        a8=0;a9=0;a10=0;a11=0;a12=0;a13=0;a14=0;a15=0;
        s0 = 0;
        s1 = 0;
        s2 = 0;
        s3 = 0;
        
        for (i = 0; i<16; i=i+1) begin
            #10
            s = i;
            s0 = s[0];
            s1 = s[1];
            s2 = s[2];
            s3 = s[3];
            if(s==4'b0000) begin a0 = 1;  end //0
            else if(s==4'b0001) begin a0=0 ; a1=1;   end//1
            else if(s==4'b0010) begin a1=0 ; a2=1;   end//2
            else if(s==4'b0011) begin a2=0 ; a3=1;   end//3
            else if(s==4'b0100) begin a3=0 ; a4=1;   end//4
            else if(s==4'b0101) begin a4=0 ; a5=1;   end//5
            else if(s==4'b0110) begin a5=0 ; a6=1;   end//6
            else if(s==4'b0111) begin a6=0 ; a7=1;   end//7
            else if(s==4'b1000) begin a7=0 ; a8=1;   end//8
            else if(s==4'b1001) begin a8=0 ; a9=1 ;  end//9
            else if(s==4'b1010) begin a9=0 ; a10=1;  end//10
            else if(s==4'b1011) begin a10=0 ; a11=1; end//11
            else if(s==4'b1100) begin a11=0 ; a12=1; end//12
            else if(s==4'b1101) begin a12=0 ; a13=1; end//13
            else if(s==4'b1110) begin a13=0 ; a14=1; end//14
            else if(s==4'b1111) begin a14=0 ; a15=1; end//15
    
        $display(" %b %b %b %b | a0=%b | a1=%b | a2=%b | a3=%b | a4=%b | a5=%b | a6=%b | a7=%b| a8=%b | a9=%b | a10=%b | a11=%b | a12=%b | a13=%b | a14=%b | a15=%b| y -->", s0,s1,s2,s3,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,y);
    end
    #10
    $finish;
    end
endmodule
