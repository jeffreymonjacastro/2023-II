module clk_divider(
    input clk,
    input reset,
    output clk_en
    );
    
    wire [27:0] din;
    wire [27:0] clkdiv;
    
    dff dff_inst0 (
    .clk(clk),
    .reset(reset),
    .D(din[0]),
    .Q(clkdiv[0])
    );

    genvar i;
    generate
        for (i = 1; i < 27; i=i+1) 
            begin : dff_gen_label
                dff dff_inst (
                .clk(clkdiv[i-1]),
                .reset(reset),
                .D(din[i]),
                .Q(clkdiv[i])
                );
            end
    endgenerate;

    assign din = ~clkdiv;
 
    assign clk_en = clkdiv[26];
 
endmodule
    