// ADD CODE BELOW
// Complete the datapath module below for Lab 11.
// You do not need to complete this module for Lab 10.
// The datapath unit is a structural SystemVerilog module. That is,
// it is composed of instances of its sub-modules. For example,
// the instruction register is instantiated as a 32-bit flopenr.
// The other submodules are likewise instantiated. 
module datapath (
	clk,
	reset,
	Adr,
	WriteData,
	ReadData,
	Instr,
	ALUFlags,
	PCWrite,
	RegWrite,
	IRWrite,
	AdrSrc,
	RegSrc,
	ALUSrcA,
	ALUSrcB,
	ResultSrc,
	ImmSrc,
	ALUControl
);
	input wire clk;
	input wire reset;
	output wire [31:0] Adr;
	output wire [31:0] WriteData;
	input wire [31:0] ReadData;
	output wire [31:0] Instr;
	output wire [3:0] ALUFlags;
	input wire PCWrite;
	input wire RegWrite;
	input wire IRWrite;
	input wire AdrSrc;
	input wire [1:0] RegSrc;
	input wire [1:0] ALUSrcA;
	input wire [1:0] ALUSrcB;
	input wire [1:0] ResultSrc;
	input wire [1:0] ImmSrc;
	input wire [1:0] ALUControl;
	wire [31:0] PCNext;
	wire [31:0] PC;
	wire [31:0] ExtImm;
	wire [31:0] SrcA;
	wire [31:0] SrcB;
	wire [31:0] Result;
	wire [31:0] Data;
	wire [31:0] RD1;
	wire [31:0] RD2;
	wire [31:0] A;
	wire [31:0] ALUResult;
	wire [31:0] ALUOut;
	wire [3:0] RA1;
	wire [3:0] RA2;

	// Your datapath hardware goes below. Instantiate each of the 
	// submodules that you need. Remember that you can reuse hardware
	// from previous labs. Be sure to give your instantiated modules 
	// applicable names such as pcreg (PC register), adrmux 
	// (Address Mux), etc. so that your code is easier to understand.

	// ADD CODE HERE
 	// next PC logic
	flopenr #(32) pcreg(
		clk, 
		reset, 
		PCWrite, 
		Result, 
		PC
	);
	
	// memory logic
	mux2 #(32) adrmux(
		PC, 
		ALUOut, 
		AdrSrc, 
		Adr
	);

	flopenr #(32) ir(
		clk, 
		reset, 
		IRWrite, 
		ReadData, 
		Instr
	);

	flopr #(32) datareg(
		clk, 
		reset, 
		ReadData, 
		Data
	);

 	// register file logic
	mux2 #(4) ra1mux(
		Instr[19:16], 
		4'b1111, 
		RegSrc[0], 
		RA1
	);

	mux2 #(4) ra2mux(
		Instr[3:0], 
		Instr[15:12], 
		RegSrc[1], 
		RA2
	);

	regfile rf(
		clk, 
		RegWrite, 
		RA1, 
		RA2,
		Instr[15:12], 
		Result, 
		Result,
		RD1, 
		RD2
	);

	flopr #(32) srcareg(
		clk, 
		reset, 
		RD1, 
		A
	);

	flopr #(32) wdreg(
		clk, 
		reset, 
		RD2, 
		WriteData
	);
	
	extend ext(
		Instr[23:0], 
		ImmSrc, 
		ExtImm
	);
	
	// ALU logic
  mux3 #(32) srcamux(
    A,
    PC,
    ALUOut,
    ALUSrcA,
    SrcA
  );

	mux3 #(32) srcbmux(
		WriteData, 
		ExtImm, 
		32'd4, 
		ALUSrcB, 
		SrcB
	);

	alu alu(
		SrcA, 
		SrcB, 
		ALUControl, 
		ALUResult, 
		ALUFlags
	);
	
	flopr #(32) aluoutreg(
		clk, 
		reset, 
		ALUResult,
		ALUOut
	);

	mux3 #(32) resmux(
		ALUOut, 
		Data, 
		ALUResult, 
		ResultSrc, 
		Result
	); 

endmodule
