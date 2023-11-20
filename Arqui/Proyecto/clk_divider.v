module clk_divider (
    input clk,
    input reset,
    output reg clk_div
    );

    reg [3:0] counter = 0;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 0;
            clk_div <= 0;
        end
        else begin
            counter <= counter + 1;
            if (counter == 10) begin
                counter <= 0;
                clk_div <= ~clk_div;
            end
        end
    end
endmodule