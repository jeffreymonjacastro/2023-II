module SR2_tb;

  reg clk;
  reg rst;
  reg [7:0] data;
  reg [31:0] data_in;
  wire [31:0] q;

  // Instancia del modulo UniversalShiftRegister
  SR2 uut (
    .clk(clk),
    .rst(rst),
    .data(data),
    .data_in(data_in),
    .q(q)
  );

  // Generacion de reloj
  always begin
    #5 clk = ~clk;
  end

  // Inicialización de las señales
  initial begin
    // $dumpfile("shift.vcd");
    // $dumpvars(0, SR2_tb);
    clk = 0;
    rst = 1; // Reset activo alto
    data = 8'b00000111; // Control inicial (sin operacion)
    data_in = 32'b1;

    // Aplicar reset
    rst = 0; data = 8'b00000111; // Load
    #3
    // Realizar operaciones
    data = 8'b00001001; // Shift left #1
    #10 data = 8'b00110001; // Shift left #6
    #10 data = 8'b11000001; // Shift left #24
    #10 data = 8'b00001011; // Shift right #1
    #10 data = 8'b00110011; // Shift right #6
    #10 data = 8'b11000011; // Shift right #24
    #10
    data = 8'b00100010;
    data_in = 32'hff0;
    rst = 0; data = 8'b00000111; // Load
    #10
    

    // Finalizar la simulación
    $finish;
  end

endmodule
