module alu ( input [31:0] a,b, // (Change)
             input [1:0] ALUControl,
             output reg [31:0] Result, //assign always block (Change)
             output wire [3:0] ALUFlags); //explicit wire for assign with {}
  
  wire negative, zero, carry, overflow; // define wire for each flag (n,z,c,v)
  wire [31:0] sum; // (Change)
  
  
  assign sum = a + (ALUControl[0]? ~b: b) + ALUControl[0]; //ADDER: two's complement
  
  /*
  ALUControl Logic
  00: sum
  01: sub
  10: and
  11: or
  */
  always @(*)
    casex (ALUControl[1:0]) //case, casex, casez
      2'b0?: Result = sum;
      2'b10: Result = a & b;
      2'b11: Result = a | b;
    endcase
  
 //flags: result -> negative, zero
  assign negative = Result[32]; // (Change)
  assign zero = (Result == 32'b0);
  //flags: additional logic -> v, c
  assign carry = (ALUControl[1]==1'b0) & sum[32]; // (Change)
  assign overflow = (ALUControl[1]==1'b0) & ~(a[32] ^ b[32] ^ ALUControl[0]) & (a[32] ^ sum[32]); // (Change)

  assign ALUFlags = {negative, zero, carry, overflow};

endmodule
