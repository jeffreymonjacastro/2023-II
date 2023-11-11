// arm_multi.v
// David_Harris@hmc.edu, Sarah_Harris@hmc.edu 25 December 2013
// Multi-cycle implementation of a subset of ARMv4

// 16 32-bit registers
// Data-processing instructions
//   ADD, SUB, AND, ORR
//   INSTR <cond> <S> <Rd>, <Rn>, #immediate
//   INSTR <cond> <S> <Rd>, <Rn>, <Rm>
//    Rd <- <Rn> INSTR <Rm>	    	if (S) Update Status Flags
//    Rd <- <Rn> INSTR immediate	if (S) Update Status Flags
//   Instr[31:28] = cond
//   Instr[27:26] = Op = 00
//   Instr[25:20] = Funct
//                  [25]:    1 for immediate, 0 for register
//                  [24:21]: 0100 (ADD) / 0010 (SUB) /
//                           0000 (AND) / 1100 (ORR)
//                  [20]:    S (1 = update CPSR status Flags)
//   Instr[19:16] = Rn
//   Instr[15:12] = Rd
//   Instr[11:8]  = 0000
//   Instr[7:0]   = immed_8  (for #immediate type) / 
//                  0000<Rm> (for register type)
//   
// Load/Store instructions
//   LDR, STR
//   INSTR <Rd>, [<Rn>, #offset]
//    LDR: Rd <- Mem[<Rn>+offset]
//    STR: Mem[<Rn>+offset] <- Rd
//   Instr[31:28] = cond
//   Instr[27:26] = Op = 01 
//   Instr[25:20] = Funct
//                  [25]:    0 (A)
//                  [24:21]: 1100 (P/U/B/W)
//                  [20]:    L (1 for LDR, 0 for STR)
//   Instr[19:16] = Rn
//   Instr[15:12] = Rd
//   Instr[11:0]  = imm (zero extended)
//
// Branch instruction (PC <= PC + offset, PC holds 8 bytes past Branch
//   B
//   INSTR <target>
//    PC <- PC + 8 + imm << 2
//   Instr[31:28] = cond
//   Instr[27:25] = Op = 10
//   Instr[25:24] = Funct
//                  [25]: 1 (Branch)
//                  [24]: 0 (link)
//   Instr[23:0]  = offset (sign extend, shift left 2)
//   Note: no Branch delay slot on ARM
//
// Other:
//   R15 reads as PC+8
//   Conditional Encoding
//    cond  Meaning                       Flag
//    0000  Equal                         Z = 1
//    0001  Not Equal                     Z = 0
//    0010  Carry Set                     C = 1
//    0011  Carry Clear                   C = 0
//    0100  Minus                         N = 1
//    0101  Plus                          N = 0
//    0110  Overflow                      V = 1
//    0111  No Overflow                   V = 0
//    1000  Unsigned Higher               C = 1 & Z = 0
//    1001  Unsigned Lower/Same           C = 0 | Z = 1
//    1010  Signed greater/equal          N = V
//    1011  Signed less                   N != V
//    1100  Signed greater                N = V & Z = 0
//    1101  Signed less/equal             N != V | Z = 1
//    1110  Always                        any
//   Writes to register 15 (PC) are ignored 

module top (
	clk,
	reset,
	WriteData,
	Adr,
	MemWrite
);
	input wire clk;
	input wire reset;
	output wire [31:0] WriteData;
	output wire [31:0] Adr;
	output wire MemWrite;
	wire [31:0] PC;
	wire [31:0] Instr;
	wire [31:0] ReadData;
	// instantiate processor and shared memory
	arm arm(
		.clk(clk),
		.reset(reset),
		.MemWrite(MemWrite),
		.Adr(Adr),
		.WriteData(WriteData),
		.ReadData(ReadData)
	);
	mem mem(
		.clk(clk),
		.we(MemWrite),
		.a(Adr),
		.wd(WriteData),
		.rd(ReadData)
	);
endmodule


module mem (
	clk,
	we,
	a,
	wd,
	rd
);
	input wire clk;
	input wire we;
	input wire [31:0] a;
	input wire [31:0] wd;
	output wire [31:0] rd;
	reg [31:0] RAM [63:0];
	initial $readmemh("memfile.dat", RAM);
	assign rd = RAM[a[31:2]]; // word aligned
	always @(posedge clk)
		if (we)
			RAM[a[31:2]] <= wd;
endmodule

	
module arm (
	clk,
	reset,
	MemWrite,
	Adr,
	WriteData,
	ReadData
);
	input wire clk;
	input wire reset;
	output wire MemWrite;
	output wire [31:0] Adr;
	output wire [31:0] WriteData;
	input wire [31:0] ReadData;
	wire [31:0] Instr;
	wire [3:0] ALUFlags;
	wire PCWrite;
	wire RegWrite;
	wire IRWrite;
	wire AdrSrc;
	wire [1:0] RegSrc;
	wire [1:0] ALUSrcA;
	wire [1:0] ALUSrcB;
	wire [1:0] ImmSrc;
	wire [1:0] ALUControl;
	wire [1:0] ResultSrc;

	controller c(
		.clk(clk),
		.reset(reset),
		.Instr(Instr[31:12]),
		.ALUFlags(ALUFlags),
		.PCWrite(PCWrite),
		.MemWrite(MemWrite),
		.RegWrite(RegWrite),
		.IRWrite(IRWrite),
		.AdrSrc(AdrSrc),
		.RegSrc(RegSrc),
		.ALUSrcA(ALUSrcA),
		.ALUSrcB(ALUSrcB),
		.ResultSrc(ResultSrc),
		.ImmSrc(ImmSrc),
		.ALUControl(ALUControl)
	);
	
	datapath dp(
		.clk(clk),
		.reset(reset),
		.Adr(Adr),
		.WriteData(WriteData),
		.ReadData(ReadData),
		.Instr(Instr),
		.ALUFlags(ALUFlags),
		.PCWrite(PCWrite),
		.RegWrite(RegWrite),
		.IRWrite(IRWrite),
		.AdrSrc(AdrSrc),
		.RegSrc(RegSrc),
		.ALUSrcA(ALUSrcA),
		.ALUSrcB(ALUSrcB),
		.ResultSrc(ResultSrc),
		.ImmSrc(ImmSrc),
		.ALUControl(ALUControl)
	);
endmodule

module controller (
	clk,
	reset,
	Instr,
	ALUFlags,
	PCWrite,
	MemWrite,
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
	input wire [31:12] Instr;
	input wire [3:0] ALUFlags;
	output wire PCWrite;
	output wire MemWrite;
	output wire RegWrite;
	output wire IRWrite;
	output wire AdrSrc;
	output wire [1:0] RegSrc;
	output wire [1:0] ALUSrcA;
	output wire [1:0] ALUSrcB;
	output wire [1:0] ResultSrc;
	output wire [1:0] ImmSrc;
	output wire [1:0] ALUControl;
	wire [1:0] FlagW;
	wire PCS;
	wire NextPC;
	wire RegW;
	wire MemW;
	decode dec(
		.clk(clk),
		.reset(reset),
		.Op(Instr[27:26]),
		.Funct(Instr[25:20]),
		.Rd(Instr[15:12]),
		.FlagW(FlagW),
		.PCS(PCS),
		.NextPC(NextPC),
		.RegW(RegW),
		.MemW(MemW),
		.IRWrite(IRWrite),
		.AdrSrc(AdrSrc),
		.ResultSrc(ResultSrc),
		.ALUSrcA(ALUSrcA),
		.ALUSrcB(ALUSrcB),
		.ImmSrc(ImmSrc),
		.RegSrc(RegSrc),
		.ALUControl(ALUControl)
	);
	condlogic cl(
		.clk(clk),
		.reset(reset),
		.Cond(Instr[31:28]),
		.ALUFlags(ALUFlags),
		.FlagW(FlagW),
		.PCS(PCS),
		.NextPC(NextPC),
		.RegW(RegW),
		.MemW(MemW),
		.PCWrite(PCWrite),
		.RegWrite(RegWrite),
		.MemWrite(MemWrite)
	);
endmodule

module decode (
	clk,
	reset,
	Op,
	Funct,
	Rd,
	FlagW,
	PCS,
	NextPC,
	RegW,
	MemW,
	IRWrite,
	AdrSrc,
	ResultSrc,
	ALUSrcA,
	ALUSrcB,
	ImmSrc,
	RegSrc,
	ALUControl
);
	input wire clk;
	input wire reset;
	input wire [1:0] Op;
	input wire [5:0] Funct;
	input wire [3:0] Rd;
	output reg [1:0] FlagW;
	output wire PCS;
	output wire NextPC;
	output wire RegW;
	output wire MemW;
	output wire IRWrite;
	output wire AdrSrc;
	output wire [1:0] ResultSrc;
	output wire [1:0] ALUSrcA;
	output wire [1:0] ALUSrcB;
	output wire [1:0] ImmSrc;
	output wire [1:0] RegSrc;
	output reg [1:0] ALUControl;
	wire Branch;
	wire ALUOp;

	// Main FSM
	mainfsm fsm(
		.clk(clk),
		.reset(reset),
		.Op(Op),
		.Funct(Funct),
		.IRWrite(IRWrite),
		.AdrSrc(AdrSrc),
		.ALUSrcA(ALUSrcA),
		.ALUSrcB(ALUSrcB),
		.ResultSrc(ResultSrc),
		.NextPC(NextPC),
		.RegW(RegW),
		.MemW(MemW),
		.Branch(Branch),
		.ALUOp(ALUOp)
	);

	// ADD CODE BELOW
	// Add code for the ALU Decoder and PC Logic.
	// Remember, you may reuse code from previous labs.
	// ALU Decoder
	always @(*)
		if (ALUOp) begin // which Data-processing Instr?
			case(Funct[4:1])
				4'b0100: ALUControl = 2'b00; // ADD
				4'b0010: ALUControl = 2'b01; // SUB
				4'b0000: ALUControl = 2'b10; // AND
				4'b1100: ALUControl = 2'b11; // ORR
				default: ALUControl = 2'bx; // unimplemented
			endcase
			
			FlagW[1] = Funct[0]; // update N & Z flags if S bit is set
			FlagW[0] = Funct[0] & (ALUControl == 2'b00 | ALUControl == 2'b01);
		end else begin
			ALUControl = 2'b00; // add for non data-processing instructions
			FlagW = 2'b00; // don't update Flags
		end

	// PC Logic
 	assign PCS = ((Rd == 4'b1111) & RegW) | Branch;  //PONER LO DEL LABO PASADO

	// Add code for the Instruction Decoder (Instr Decoder) below.
	// Recall that the input to Instr Decoder is Op, and the outputs are
	// ImmSrc and RegSrc. We've completed the ImmSrc logic for you.

	// Instr Decoder
	assign ImmSrc = Op;
	assign RegSrc[0] = (Op == 2'b10); // read PC on Branch
	assign RegSrc[1] = (Op == 2'b01); // read Rd on STR 
endmodule

module mainfsm (
	clk,
	reset,
	Op,
	Funct,
	IRWrite,
	AdrSrc,
	ALUSrcA,
	ALUSrcB,
	ResultSrc,
	NextPC,
	RegW,
	MemW,
	Branch,
	ALUOp
);
	input wire clk;
	input wire reset;
	input wire [1:0] Op;
	input wire [5:0] Funct;
	output wire IRWrite;
	output wire AdrSrc;
	output wire [1:0] ALUSrcA;
	output wire [1:0] ALUSrcB;
	output wire [1:0] ResultSrc;
	output wire NextPC;
	output wire RegW;
	output wire MemW;
	output wire Branch;
	output wire ALUOp;
	reg [3:0] state;
	reg [3:0] nextstate;
	reg [12:0] controls;
	localparam [3:0] FETCH = 0;
	localparam [3:0] DECODE = 1;
	localparam [3:0] MEMADR = 2;
	localparam [3:0] MEMRD = 3;
	localparam [3:0] MEMWB = 4;
	localparam [3:0] MEMWR = 5;
	localparam [3:0] EXECUTER = 6;
	localparam [3:0] EXECUTEI = 7;
	localparam [3:0] ALUWB = 8;
	localparam [3:0] BRANCH = 9;
	localparam [3:0] UNKNOWN = 10;

	// state register
	always @(posedge clk or posedge reset)
		if (reset)
			state <= FETCH;
		else
			state <= nextstate;
	

	// ADD CODE BELOW
  	// Finish entering the next state logic below.  We've completed the 
  	// first two states, FETCH and DECODE, for you.

  	// next state logic
	always @(*)
		casex (state)
			FETCH: begin
				nextstate = DECODE;
			end
			DECODE: begin
				case (Op)
					2'b00:
						if (Funct[5])
							nextstate = EXECUTEI;
						else
							nextstate = EXECUTER;
					2'b01: nextstate = MEMADR;
					2'b10: nextstate = BRANCH;
					default: nextstate = UNKNOWN;
				endcase
			end

			EXECUTER: begin 
				nextstate = ALUWB;
			end
			EXECUTEI: begin
				nextstate = ALUWB;
			end
			MEMADR: begin
				if(Funct[0])	
					nextstate = MEMRD;
				else nextstate = MEMWR;
			end
			MEMRD:begin
				nextstate = MEMWB;
			end
			default: begin 
				nextstate = FETCH;
			end
		endcase

	// ADD CODE BELOW
	// Finish entering the output logic below.  We've entered the
	// output logic for the first two states, FETCH and DECODE, for you.

	// state-dependent output logic
	always @(*)
		case (state)
      // NextPC = 1
      // Branch = 1
      // MemW = 1
      // RegW = 1
      // IRWrite = 1
      // AdrSrc = 1
      // ResultSrc = 11
      // ALUSrcA = 11
      // ALUSrcB = 11
      // ALUOp = 1
			FETCH: controls = 13'b10001_0100_1100;   
			DECODE: controls = 13'b00000_0100_1100;
			MEMADR: controls = 13'b00000_0000_0010; 
			MEMRD:  controls = 13'b00000_1000_0000;
			MEMWB: controls = 13'b00010_0010_0000; 
			MEMWR: controls = 13'b00100_1000_0000; 
			EXECUTER: controls = 13'b00000_0000_0001;
			EXECUTEI: controls = 13'b00000_0000_0011;
			ALUWB: controls = 13'b00010_0000_0000; 
			BRANCH: controls = 13'b01000_0101_0010; 
			default: controls = 13'bxxxxxxxxxxxx;
		endcase
	assign {NextPC, Branch, MemW, RegW, IRWrite, AdrSrc, ResultSrc, ALUSrcA, ALUSrcB, ALUOp} = controls;
endmodule

// ADD CODE BELOW
// Add code for the condlogic and condcheck modules. Remember, you may
// reuse code from prior labs.
module condlogic (
	clk,
	reset,
	Cond,
	ALUFlags,
	FlagW,
	PCS,
	NextPC,
	RegW,
	MemW,
	PCWrite,
	RegWrite,
	MemWrite
);
	input wire clk;
	input wire reset;
	input wire [3:0] Cond;
	input wire [3:0] ALUFlags;
	input wire [1:0] FlagW;
	input wire PCS;
	input wire NextPC;
	input wire RegW;
	input wire MemW;
	output wire PCWrite;
	output wire RegWrite;
	output wire MemWrite;
	
	wire [1:0] FlagWrite;
	wire [3:0] Flags;
	wire CondEx , CondExDelayed; // FALTA DEL DELAY
	
	// Delay writing flags until ALUWB state
	// // ME RETIRO
	// flopr #(2) flagwritereg(
	// 	clk,
	// 	reset,
	// 	FlagW & {2 {CondEx}},
	// 	FlagWrite
	// );

	// ADD CODE HERE

	flopenr #(2) flagreg1(
		clk, 
		reset, 
		FlagWrite[1], 
		ALUFlags[3:2],
		Flags[3:2]
	);
	
	flopenr #(2) flagreg0( 
		clk, 
		reset, 
		FlagWrite[0], 
		ALUFlags[1:0],
		Flags[1:0]
	);

	// write controls are conditional
	condcheck cc(
		Cond, 
		Flags, 
		CondEx
	);

	flopr #(1) condreg(
		clk, 
		reset, 
		CondEx, 
		CondExDelayed
	);

	assign FlagWrite = FlagW & {2{CondEx}};
	assign RegWrite = RegW & CondExDelayed;
	assign MemWrite = MemW & CondExDelayed;
	assign PCWrite = (PCS & CondExDelayed) | NextPC;

endmodule

module condcheck (
	Cond,
	Flags,
	CondEx
);
	input wire [3:0] Cond;
	input wire [3:0] Flags;
	output reg CondEx;

	// ADD CODE HERE
	wire neg, zero, carry, overflow, ge; 
	assign {neg, zero, carry, overflow} = Flags;
    assign ge = (neg == overflow); 
	always @(*)
		case (Cond)
			4'b0000: CondEx = zero;
			4'b0001: CondEx = ~zero;
			4'b0010: CondEx = carry;
			4'b0011: CondEx = ~carry;
			4'b0100: CondEx = neg;
			4'b0101: CondEx = ~neg;
			4'b0110: CondEx = overflow;
			4'b0111: CondEx = ~overflow;
			4'b1000: CondEx = carry & ~zero;
			4'b1001: CondEx = ~(carry & ~zero);
			4'b1010: CondEx = ge;
			4'b1011: CondEx = ~ge;
			4'b1100: CondEx = ~zero & ge;
			4'b1101: CondEx = ~(~zero & ge);
			4'b1110: CondEx = 1'b1;
			default: CondEx = 1'bx;
		endcase
endmodule

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

// ADD CODE BELOW
// Add needed building blocks below (i.e., parameterizable muxes, 
// registers, etc.). Remember, you can reuse code from previous labs.
// We've also provided a parameterizable 3:1 mux below for your 
// convenience.
module alu (input [31:0] a,b,
            input [1:0] ALUControl,
            output reg [31:0] Result, //assign always block
            output wire [3:0] ALUFlags); //explicit wire for assign with {}
  
  wire negative, zero, carry, overflow; // define wire for each flag (n,z,c,v)
  wire [32:0] sum;
  
  
  assign sum = a + (ALUControl[0]? ~b: b) + ALUControl[0]; //ADDER: two's complement
  
  /*
  ALUControl Logic
  00: sum
  01: sub
  10: and
  11: or
  */
  always @(*)
    casex (ALUControl[1:0]) //case, casex, casez
      2'b0?: Result = sum;
      2'b10: Result = a & b;
      2'b11: Result = a | b;
    endcase
  
 //flags: result -> negative, zero
  assign negative = Result[31];
  assign zero = (Result == 32'b0);
  //flags: additional logic -> v, c
  assign carry = (ALUControl[1]==1'b0) & sum[32];
  assign overflow = (ALUControl[1]==1'b0) & ~(a[31] ^ b[31] ^ ALUControl[0]) & (a[31] ^ sum[31]);

  assign ALUFlags = {negative, zero, carry, overflow};

endmodule

module mux3 (
	d0,
	d1,
	d2,
	s,
	y
);
	parameter WIDTH = 8;
	input wire [WIDTH - 1:0] d0;
	input wire [WIDTH - 1:0] d1;
	input wire [WIDTH - 1:0] d2;
	input wire [1:0] s;
	output wire [WIDTH - 1:0] y;
	assign y = (s[1] ? d2 : (s[0] ? d1 : d0));
endmodule

module extend (
	Instr,
	ImmSrc,
	ExtImm
);
	input wire [23:0] Instr;
	input wire [1:0] ImmSrc;
	output reg [31:0] ExtImm;
	always @(*)
		case (ImmSrc)
			2'b00: ExtImm = {24'b000000000000000000000000, Instr[7:0]};
			2'b01: ExtImm = {20'b00000000000000000000, Instr[11:0]};
			2'b10: ExtImm = {{6 {Instr[23]}}, Instr[23:0], 2'b00};
			default: ExtImm = 32'bxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx;
		endcase
endmodule

module adder (
	a,
	b,
	y
);
	parameter WIDTH = 8;
	input wire [WIDTH - 1:0] a;
	input wire [WIDTH - 1:0] b;
	output wire [WIDTH - 1:0] y;
	assign y = a + b;
endmodule

module flopenr (
	clk,
	reset,
	en,
	d,
	q
);
	parameter WIDTH = 8;
	input wire clk;
	input wire reset;
	input wire en;
	input wire [WIDTH - 1:0] d;
	output reg [WIDTH - 1:0] q;
	always @(posedge clk or posedge reset)
		if (reset)
			q <= 0;
		else if (en)
			q <= d;
endmodule

module flopr (
	clk,
	reset,
	d,
	q
);
	parameter WIDTH = 8;
	input wire clk;
	input wire reset;
	input wire [WIDTH - 1:0] d;
	output reg [WIDTH - 1:0] q;
	always @(posedge clk or posedge reset)
		if (reset)
			q <= 0;
		else
			q <= d;
endmodule

module mux2 (
	d0,
	d1,
	s,
	y
);
	parameter WIDTH = 8;
	input wire [WIDTH - 1:0] d0;
	input wire [WIDTH - 1:0] d1;
	input wire s;
	output wire [WIDTH - 1:0] y;
	assign y = (s ? d1 : d0);
endmodule

module regfile (
	clk,
	we3,
	ra1,
	ra2,
	wa3,
	wd3,
	r15,
	rd1,
	rd2
);
	input wire clk;
	input wire we3;
	input wire [3:0] ra1;
	input wire [3:0] ra2;
	input wire [3:0] wa3;
	input wire [31:0] wd3;
	input wire [31:0] r15;
	output wire [31:0] rd1;
	output wire [31:0] rd2;
	reg [31:0] rf [14:0];
	
	always @(posedge clk)
		if (we3)
			rf[wa3] <= wd3;
	assign rd1 = (ra1 == 4'b1111 ? r15 : rf[ra1]);
	assign rd2 = (ra2 == 4'b1111 ? r15 : rf[ra2]);
endmodule
