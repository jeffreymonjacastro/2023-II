module visor_tb;
    reg pl, re, ff, st, m, clk, reset;
    wire P, R, F;

    visor visorvr(pl, re, ff, st, m, clk, reset, P, R, F);

    always begin
        #5 clk = ~clk; 
    end

    initial begin
        clk = 0; pl = 0; re = 0; ff = 0; st = 0; m = 1; reset = 1;
        #3
        reset = 0;
        #10
        pl = 1; re = 0; ff = 0; st = 0;
        #10
        pl = 1; re = 1; ff = 0; st = 0;
        #10
        pl = 1; re = 0; ff = 0; st = 0;
        #10
        pl = 1; st = 0; m = 0;
        #10
        pl = 1; re = 0; ff = 1; st = 0; m = 1;
        #10
        pl = 1; re = 0; ff = 0; st = 0;
        #10
        pl = 1; st = 0; m = 0;
        #10
        reset = 1;
        #10
        reset = 0;
        #10 $finish; 
    end

endmodule
