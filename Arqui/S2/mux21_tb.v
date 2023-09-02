module mux21_tb;
  reg a, b, s;
  wire y;
  
  mux21 M(.y(y), .a(a), .b(b), .s(s)); 

  initial begin
    a = 0;
    b = 0;
    s = 0;
    #80 $finish;
  end

  always #40 a = ~a;
  always #20 b = ~b;
  always #10 s = ~s;

  initial begin
    $monitor("%2d:\ta=%b\tb=%b\ts=%b\ty=%b", $time, a, b, s, y);
  end

endmodule