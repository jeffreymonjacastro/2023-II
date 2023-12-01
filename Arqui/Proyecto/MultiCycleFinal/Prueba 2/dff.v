module dff(
    input D,
    input clk,
    input reset,
    output reg Q
    );
 
    always @ (posedge(clk), posedge(reset))
        begin
            if (reset == 1)
                Q <= 1'b0;
            else
                Q <= D;
        end
endmodule