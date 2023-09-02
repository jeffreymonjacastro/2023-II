module primos_tb;
  initial begin
    $dumpfile("primos.vcd");
    $dumpvars;
  end

  reg a,b,c;
  wire y;
  primos p(a,b,c,y);

  initial begin
    a = 0; b = 0; c = 0;
    #1
    a = 0; b = 0; c = 1;
    #1
    a = 0; b = 1; c = 0;
  end

  initial begin 
    $monitor("%2d:\ta=%b\tb=%b\tc=%b\ty=%b",$time,a,b,c,y);
  end

endmodule