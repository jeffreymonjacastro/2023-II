module sr_chiquito_tb;

  reg clk;
  reg rst;
  reg [7:0] data;
  reg [7:0] data_in;
  wire [7:0] q;

  // Instancia del módulo UniversalShiftRegister
  sr_chiquito uut (
    .clk(clk),
    .rst(rst),
    .data(data),
    .data_in(data_in),
    .q(q)
  );

  // Generación de reloj
  always begin
    #5 clk = ~clk;
  end

  // Inicialización de las señales
  initial begin
    // $dumpfile("shift.vcd");
    // $dumpvars(0, sr_chiquito_tb);
    clk = 0;
    rst = 1; // Reset activo alto
    data = 8'b00000111; // Control inicial (sin operación)
    data_in = 8'b1;

    // Aplicar reset
    #3
    rst = 0; 
    data = 8'b00000111; // Load
    #3
    // Realizar operaciones
    data = 8'b00001001; // Shift left #1
    #10 data = 8'b00001001; // Shift left #4
    #10 data = 8'b00001001; // Shift left #2
    #10 data = 8'b00001011; // Shift right #1
    #10 data = 8'b00001011; // Shift right #4
    #10 data = 8'b00001011; // Shift right #2
    #10

    // Finalizar la simulación
    $finish;
  end

endmodule
