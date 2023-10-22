module imem (
	a,
	rd
);
	input wire [31:0] a;
	output wire [31:0] rd;
	wire [31:0] RAM [63:0]; // reg ?
	initial $readmemh("memfile.dat", RAM);
	assign rd = RAM[a[31:2]];
endmodule