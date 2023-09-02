module mux21 (y, a, b, s);
  input a, b, s;
  output y;

  assign y = a & ~s | b & s;

endmodule