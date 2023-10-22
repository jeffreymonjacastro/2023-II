module alu_tb();
  reg [31:0] a,b;
  wire [3:0] ALUFlags;
  reg [1:0] ALUControl;
  reg clk, reset;
  reg [101:0] testvector[1000:0];
  wire [31:0] Result;
  reg [31:0] Result_expected; // to compare y output
  reg [3:0] ALUFlags_expected;
  reg [31:0] vectornum; // check testvector number
  reg [31:0] errors; // error counter
  
  
  alu dut(.a(a),.b(b),.ALUControl(ALUControl),.Result(Result),.ALUFlags(ALUFlags));
  
  always // always execute
    begin
      clk=1; #5; clk=0; #5;    
    end
  
  initial // one exec
    begin
      $readmemh("alu_tv.tv", testvector);      // readmemb("filename",dest):  read file b is binary formay, h is hexadecimal format
      errors=0;
      vectornum=0;
      reset = 1; #17; reset=0;
    end
  
  //use clock posedge for inputs
  always @(posedge clk)
    begin
      ALUFlags_expected=testvector[vectornum][3:0];
      Result_expected=testvector[vectornum][35:4];
      b = testvector[vectornum][67:36];
      a = testvector[vectornum][99:68];
      ALUControl = testvector[vectornum][101:100];
    end
  
  //use clock negedge for output check
  always @(negedge clk)
    begin
    if  (~reset)
      begin
    //Important: difference between == and ===, the latter compares also X!!
      if ((Result !== Result_expected) || (ALUFlags !== ALUFlags_expected))
        begin
            $display("testvector: %h",testvector[vectornum]);
            $display("Vectornum: %d",vectornum);
            $display("Error input a: %h",{a});
            $display("Error input b: %h",{b});
            $display("Error input ALUControl: %h",{ALUControl});
            $display("output Result:%h, Result_expected:%b",Result,Result_expected);
            $display("output ALUFlags:%h, ALUFlags_expected:%b",ALUFlags, ALUFlags_expected);
          errors=errors+1;
        end
  
      vectornum=vectornum+1;

      if (testvector[vectornum][0] === 1'bx)
      /* if (vectornum == 6) // can also use the end of file as reference, 
      but it is a limited solution */
        begin
          $display("total errors: %d",errors);
          $finish;  
        end
    end
    end
    initial begin
          $dumpfile("alu.vcd");
          $dumpvars;
    end
endmodule 