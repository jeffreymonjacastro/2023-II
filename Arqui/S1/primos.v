// Behavioral description of the circuit "primos"
module primos(input a,b,c, output y)
  assign y = ~a & b | b & c;

endmodule

/* Comment */