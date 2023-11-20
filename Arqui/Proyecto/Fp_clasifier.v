module Fp_clasifier(
  input [15:0] float, 
  output snan, qnan, inf, zero, subnormal, normal 
);

  wire expOnes, expZeroes, sigZeroes ; 

  assign expOnes = &float[14:10];
  assign expZeroes = ~|float[14:10];
  assign sigZeroes = ~|float[9:0];

  assign snan = expOnes & ~sigZeroes & ~float[9];
  assign qnan = expOnes & float[9];
  assign inf  = expOnes & sigZeroes;
  assign zero = expZeroes & sigZeroes;
  assign subnormal = expZeroes & ~sigZeroes;
  assign normal = ~expOnes &  ~expZeroes;

endmodule