module controller (
	clk,
	reset,
	Instr,
	ALUFlags,
	RegSrc,
	RegWrite,
	ImmSrc,
	ALUSrc,
	LDRB,
	ALUControl,
	MemWrite,
	MemtoReg,
	PCSrc
);
	input wire clk;
	input wire reset;
	input wire [31:12] Instr;
	input wire [3:0] ALUFlags;
	output wire [1:0] RegSrc;
	output wire RegWrite;
	output wire [1:0] ImmSrc;
	output wire ALUSrc;
	output wire LDRB;
	output wire [2:0] ALUControl;
	output wire MemWrite;
	output wire MemtoReg;
	output wire PCSrc;

	wire [1:0] FlagW;
	wire PCS;
	wire RegW;
	wire MemW;

	// Modulo decoder
	decode dec(
		.Op(Instr[27:26]),  			// Opcode = 00 | 01 | 10
		.Funct(Instr[25:20]), 		// Funct (6-bits) 
		.Rd(Instr[15:12]),				// Register Destination (4-bits)
		.FlagW(FlagW),
		.PCS(PCS),
		.RegW(RegW),
		.MemW(MemW),
		.MemtoReg(MemtoReg),
		.ALUSrc(ALUSrc),
		.LDRB(LDRB),
		.ImmSrc(ImmSrc),					// Immediate Source (2 bit)
		.RegSrc(RegSrc),		 			// Register Source (2 bit)
		.ALUControl(ALUControl)   // ALUControl (3 bit) = 00 ADD | 01 SUB | 10 AND | 11 ORR
	);

	// Modulo Conditional Logic
	condlogic cl(
		.clk(clk),
		.reset(reset),
		.Cond(Instr[31:28]),			// Condition (4-bits)
		.ALUFlags(ALUFlags),
		.FlagW(FlagW),
		.PCS(PCS),
		.RegW(RegW),
		.MemW(MemW),
		.PCSrc(PCSrc),
		.RegWrite(RegWrite),
		.MemWrite(MemWrite)
	);
endmodule