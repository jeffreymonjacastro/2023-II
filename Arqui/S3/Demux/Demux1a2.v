module Demux1a2(x, y, a, s);
  input a, s;
  output x, y;

  always @(s or a0 or a1) begin 
    case (s)
      1'b0: x = a;
      1'b1: y = a;
    endcase
  end
endmodule