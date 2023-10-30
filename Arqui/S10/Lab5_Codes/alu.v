module alu ( input [31:0] a,b, // (Change)
              input [2:0] ALUControl,
              output reg [31:0] Result, //assign always block (Change)
              output wire [3:0] ALUFlags); //explicit wire for assign with {}
  
  wire negative, zero, carry, overflow; // define wire for each flag (n,z,c,v)
  wire [31:0] sum; // (Change)
  
  
  assign sum = a + (ALUControl[0] ? ~b: b) + ALUControl[0]; //ADDER: two's complement
  
  /*
  ALUControl Logic
  00: sum
  01: sub
  10: and
  11: or
  */
  always @(*)
    casex (ALUControl[2:0]) //case, casex, casez
      3'b00?: Result = sum;
      3'b010: Result = a & b;
      3'b011: Result = a | b;
      3'b110: Result = a ^ b;
    endcase
  
 //flags: result -> negative, zero
  assign negative = Result[31]; 
  assign zero = (Result == 32'b0);
  //flags: additional logic -> v, c
  assign carry = (ALUControl[1]==1'b0) & sum[32]; 
  assign overflow = (ALUControl[1]==1'b0) & ~(a[31] ^ b[31] ^ ALUControl[0]) & (a[31] ^ sum[31]);

  assign ALUFlags = {negative, zero, carry, overflow};

endmodule
