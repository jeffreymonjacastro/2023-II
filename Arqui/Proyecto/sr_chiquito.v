module sr_chiquito (
  input wire clk,           // Reloj
  input wire rst,           // Reset
  input wire [7:0] data,    //bits 11-4
  input wire [7:0] data_in, // Datos de entrada
  output reg [7:0] q        // Salida del shift register
);
  integer width_;
  integer i;
  
  always @* begin
    width_ = 0;
    for (i = 3 ; i <= 7 ; i = i + 1)begin
      if (data[i] == 1) begin
        width_ = width_ + (2 ** (i-3));
      end
    end
  end
  
  always @(posedge clk or posedge rst) begin
    if (rst) begin
      q <= 8'b0;  // Reset del registro
    end else begin
      // Realizar operaciones según el control de entrada
      casex (data[2:1])
        2'b00: begin
          q <= q << width_; // Shift left LSL
        end
        2'b01: begin
          q <= q >> width_; // Shift right LSR
        end
        2'b11: q <= data_in; // Load
        default: ; // No hace nada para 2'b00
      endcase
    end
  end

endmodule
