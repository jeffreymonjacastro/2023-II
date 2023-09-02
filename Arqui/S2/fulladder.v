module fulladder(s,c,a,b,cin);
  input a, b, cin;
  output s, c;
  wire n1,n2,n3,n4;

  // Para el s
  xor xor1(n1, a, b);
  xor xor2(s, n1, cin);

  // Para el c
  and and1(n2, a, b);
  and and2(n3, a, cin);
  and and3(n4, b, cin);
  or or1(c, n2, n3, n4);
endmodule