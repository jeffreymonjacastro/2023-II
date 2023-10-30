module arm (
	clk,
	reset,
	PC,
	Instr,
	MemWrite,
	ALUResult,
	WriteData,
	ReadData
);
	
	input wire clk;
	input wire reset;
	output wire [31:0] PC;	
	input wire [31:0] Instr;
	output wire MemWrite;
	output wire [31:0] ALUResult;
	output wire [31:0] WriteData;
	input wire [31:0] ReadData;
	
	wire [3:0] ALUFlags;
	wire RegWrite;
	wire ALUSrc;
	wire LDRB;
	wire MemtoReg;
	wire PCSrc;
	wire [1:0] RegSrc;
	wire [1:0] ImmSrc;
	wire [2:0] ALUControl;

	// Modulo controller
	controller c(
		.clk(clk),
		.reset(reset),
		.Instr(Instr[31:12]),
		.ALUFlags(ALUFlags),
		.RegSrc(RegSrc),
		.RegWrite(RegWrite),
		.ImmSrc(ImmSrc),
		.ALUSrc(ALUSrc),
		.LDRB(LDRB),
		.ALUControl(ALUControl),
		.MemWrite(MemWrite),
		.MemtoReg(MemtoReg),
		.PCSrc(PCSrc)
	);

	// Modulo datapath
	datapath dp(
		.clk(clk),
		.reset(reset),
		.RegSrc(RegSrc),
		.RegWrite(RegWrite),
		.ImmSrc(ImmSrc),
		.ALUSrc(ALUSrc),
		.LDRB(LDRB),
		.ALUControl(ALUControl),
		.MemtoReg(MemtoReg),
		.PCSrc(PCSrc),
		.ALUFlags(ALUFlags),
		.PC(PC),
		.Instr(Instr),
		.ALUResult(ALUResult),
		.WriteData(WriteData),
		.ReadData(ReadData)
	);
endmodule