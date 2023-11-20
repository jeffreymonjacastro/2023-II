module clk_divider_tb;
  reg clk;
  reg reset;
  wire clk_div;

  clk_divider clk_divider_inst (
    .clk(clk),
    .reset(reset),
    .clk_div(clk_div)
  );

  initial begin
    $dumpfile("clk_divider_tb.vcd");
    $dumpvars(0, clk_divider_tb);
    clk = 0;
    reset = 1;
    #10 reset = 0;
    #10000 $finish;
  end

  always #5 clk = ~clk;
endmodule