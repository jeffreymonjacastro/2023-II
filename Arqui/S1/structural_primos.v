// Structural description of the circuit "primos"
module primos(input a,b,c, output y);
  wire(na,n1,n2);
  not(na,a);
  and(n1,na,b);
  and(n2,b,c);
  or(y,n1,n2);
endmodule

