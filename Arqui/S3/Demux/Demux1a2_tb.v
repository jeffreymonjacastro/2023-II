module Demux1a2_tb;
  wire x, y;
  reg a, s;

  Demux1a2 d(x, y, a, s);

  initial begin
    $dumpfile("Demux1a2.vcd");
    $dumpvars;

    a = 0; s = 0;
    #10 
    a = 0; s = 1;
    #10
    a = 1; s = 0;
    #10
    a = 1; s = 1;
  end

  initial begin
    $monitor("%2d:\ta=%b\ts=%b\tx=%b\ty=%b",$time,a,s,x,y);
  end
endmodule