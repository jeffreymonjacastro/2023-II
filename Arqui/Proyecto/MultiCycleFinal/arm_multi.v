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
	wire Shift; // LSL

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
		.ALUControl(ALUControl),
		.Shift(Shift)
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
		.ALUControl(ALUControl),
		.Shift(Shift)
	);
endmodule

module controller (  // zona de control del datapath
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
	ALUControl,
	Shift
);
	input wire clk; //reloj del datapath
	input wire reset; // reset del datapath
	input wire [31:12] Instr; // instruccion usada en el datapath en la etapa del decode
	input wire [3:0] ALUFlags; // Aluflags del datapath
	output wire PCWrite;//Control para el flop enable que permite actualizar el Pogram Counter
	output wire MemWrite; //Control de memoria para escribir en memoria
	output wire RegWrite; // Control de memoria de registro para escribir en uno de los 16 registros
	output wire IRWrite; // Control del flop enable para escribir la instruccion a la he se la hecho el fetch
	output wire AdrSrc; // Controla si estamos trabajando con un address para program counter o un address para memoria 
	output wire [1:0] RegSrc;// Controla si estamos trabajando con Rn o Rs o Rm en alguno de los registros que pasan hacia A1 o A2
	output wire [1:0] ALUSrcA; // Controla si estamos trabajando con el PC o con el registro A1 (que se lee del estado no arquitectural de A) o si se esta procesando un branch
	output wire [1:0] ALUSrcB; //Controla si trabajamos con el registro A2 o con la extension de la inmediata o con el 4 para actulizar el PC 
	output wire [1:0] ResultSrc; //Controla los resultados si es el resultado de la ALU o el resultado de la memoria o se actuliza el program counter para un branch
	output wire [1:0] ImmSrc; //Controla los modos del extend para el modulo immediate
	output wire [1:0] ALUControl; //Controles de operacion para el ALU
	output wire Shift; //Controla si se hace un shift o no
	wire [1:0] FlagW; //Las flags del ALU
	wire PCS; // Se alimenta a la logica condicional para luego poder actualizar el PC según CondEX
	wire NextPC; // Se usa en la lógica condicional para actualizar el PC junto de esta forma NextPC || (PCs && CondEx)
	wire RegW; // Se usa para la lógica condicional junto con CondEx para actualizar los registros
	wire MemW; // Se usa para la lógica condicional junto con CondEx para escribir en memoria 

	//Codigo para el decoder donde se usa la FSM para controlar el datapath
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
		.ALUControl(ALUControl),
		.Shift(Shift)
	);
	//EL condlogic que trabaja con algunos controles del decoder
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
	ALUControl,
	Shift
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
	output reg Shift;
	output reg [1:0] ALUControl;
	wire Branch;
	wire ALUOp;

	// LA MAQUINA DE ESTADOS PARA CONTROLAR  EL DATAPATH ALGUNO DE ESTOS CONTROLES SE VAN AL MODULO COND LOGIC
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


	// DECODIFICADOR DE ALU ESTE MODULO ES UN MODULO COMBINACIONAL QUE CONTROLA LAS OPERACIONAES DEL ALU
	always @(*)
		if (ALUOp) begin // Que instruccion se usa
			case(Funct[4:1])
				4'b0100: 
					begin
					ALUControl = 2'b00; // ADD
					Shift = 1'b0;
					end
		
				4'b0010: 
					begin
					ALUControl = 2'b01; // SUB
					Shift = 1'b0;
					end
				4'b0000: 
					begin
					ALUControl = 2'b10; // AND
					Shift = 1'b0;
					end
				4'b1100: 
					begin
					ALUControl = 2'b11; // ORR
					Shift = 1'b0;
					end
				4'b1101: 
					begin
					ALUControl = 2'b00; // shift
					Shift = 1'b1; // Se hace un shift
					end
				default: ALUControl = 2'bx; // no implementado
			endcase
			
			FlagW[1] = Funct[0]; // actualiza N & Z flags si el bit  S bit se ha seteado
			FlagW[0] = Funct[0] & (ALUControl == 2'b00 | ALUControl == 2'b01);
		end else begin
			ALUControl = 2'b00; // add para operaciones que no son de procesamiento de data
			FlagW = 2'b00; // No actuliza los flags
		end

	// LOGICA DEL PROGRAM COUNTER
 	assign PCS = ((Rd == 4'b1111) & RegW) | Branch;  //Logica para actualizar el PC

	// DECODIFICADOR DE INSTRUCCIONES
	//Como el FSM es una maquina de moore se hace esto para que no dependan de los inputs 
	assign ImmSrc = Op; //trabajar con immediate depende de la operacion
	assign RegSrc[0] = (Op == 2'b10); // Leer el program counter en branch
	assign RegSrc[1] = (Op == 2'b01); // leer Rd en operacion de guardado (str)
endmodule

module mainfsm ( // controlador FSM 
	clk, // reloj del FSM 
	reset,// reset del FSM
	Op, //  Modo de operacion
	Funct, // FUNC de la instruccion [5:0]
	IRWrite, // Control de escritura de la instruccion
	AdrSrc, // Control de la fuente de la direccion
	ALUSrcA, // Control de la fuente A de la ALU
	ALUSrcB, // Control de la fuente B de la ALU
	ResultSrc, // Control de la fuente del resultado
	NextPC,// Control de la actualizacion del PC
	RegW,// Control de la escritura de los registros
	MemW,// Control de la escritura en memoria
	Branch, // Control de la operacion de branch
	ALUOp // Control de la operacion del ALU esto se alimenta al ALU Decoder
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

	// Register de los estados que controla la FSM
	always @(posedge clk or posedge reset)
		if (reset)
			state <= FETCH; // EL Reset para toda instrucción es el FETCH
		else
			state <= nextstate;
	

  // Logica del estado siguiente
	always @(*)
		casex (state)
			FETCH: begin // El primer estado de toda instruccion es FETCH
				nextstate = DECODE; // Se pasa invariantemente hacia el estado de DECODE
			end
			DECODE: begin // Aca se pasan las instrucciones 
				case (Op)
					2'b00://Data processing
						if (Funct[5]) // Immediate para cualquier operacion (es el valor I en el machine code)
							nextstate = EXECUTEI;
						else
							nextstate = EXECUTER; //Register para cualquier operacion
					2'b01: nextstate = MEMADR; // Load/Store
					2'b10: nextstate = BRANCH; // Branch
					default: nextstate = UNKNOWN;
				endcase
			end
			// AMBOS ESTADOS SIGUIENTES EN DATA PROCESSING VAN HACIA ALUWB
			EXECUTER: begin  // Se pasa a ALUWB , es decir se pasa a la etapa de escritura de los registros
				nextstate = ALUWB;
			end
			EXECUTEI: begin // Se pasa a ALUWB , es decir se pasa a la etapa de escritura de los registros
				nextstate = ALUWB;
			end
			MEMADR: begin //Estado para pasar el address a memoria
				if(Funct[0])	// Si es un load se pasa a MEMRD (si es 0 a STR si es 1 LDR)
					nextstate = MEMRD; // Se pasa a MEMRD para leer de memoria
				else nextstate = MEMWR; //Se pasa a MEMWR para escribir en memoria (este a su vez pasa con transicion espontanea a fetch)
			end
			MEMRD:begin 
				nextstate = MEMWB; // Se pasa a MEMWB para escribir en los registros
			end
			default: begin 
				nextstate = FETCH; // Alguna transicion espontanea no puesta explicitamente va hacia fetch 
			end
		endcase

	// lógica de salida dependiente del estado actual
	always @(*)
		case (state)
			FETCH: controls = 13'b1_0_0_0_1_0_10_01_10_0; 
			DECODE: controls = 13'b0_0_0_0_0_0_10_01_10_0;
			MEMADR: controls = 13'b0_0_0_0_0_0_00_00_01_0; 
			MEMRD:  controls = 13'b0_0_0_0_0_1_00_00_00_0;
			MEMWB: controls = 13'b0_0_0_1_0_0_01_00_00_0; 
			MEMWR: controls = 13'b0_0_1_0_0_1_00_00_00_0; 
			EXECUTER: controls = 13'b0_0_0_0_0_0_00_00_00_1;
			EXECUTEI: controls = 13'b0_0_0_0_0_0_00_00_01_1;
			ALUWB: controls = 13'b0_0_0_1_0_0_00_00_00_0;
			BRANCH: controls = 13'b0_1_0_0_0_0_10_10_01_0; 
			default: controls = 13'bxxxxxxxxxxxx;
		endcase
	assign {NextPC, Branch, MemW, RegW, IRWrite, AdrSrc, ResultSrc, ALUSrcA, ALUSrcB, ALUOp} = controls;
endmodule


module condlogic ( // Logica condicional para controlar el hecho de actualizar el PC, escribir en memoria o escribir en los registros
	clk, // reloj del cond logic
	reset, // reset del cond logic
	Cond, // Condicion de la instruccion
	ALUFlags, // Flags de la ALU
	FlagW, // Flags de escritura
	PCS, // Control de actualizacion del PC que viene del Main FSM decoder
	NextPC, // Control de actualizacion del PC que viene del Main FSM decoder
	RegW, // Control de escritura de los registros que viene del Main FSM decoder
	MemW, // Control de escritura en memoria que viene del Main FSM decoder
	PCWrite,  // Control de escritura del PC que se pasa al datapath
	RegWrite, // Control de escritura de los registros que se pasa al datapath
	MemWrite // Control de escritura en memoria que se pasa al datapath
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
	wire CondEx , CondExDelayed;  //CondExDelayed es el resultado no arquitectural que viene del flop contectado a la salida de cond logic
	

	// ADD CODE HERE

	flopenr #(2) flagreg1( // Flop enable para las flags  N , Z
		clk, 
		reset, 
		FlagWrite[1], 
		ALUFlags[3:2],
		Flags[3:2]
	);
	
	flopenr #(2) flagreg0(  // Flop enable para las flags  C , V
		clk, 
		reset, 
		FlagWrite[0], 
		ALUFlags[1:0],
		Flags[1:0]
	);


	condcheck cc( // Logica condicional para actualizar los controles de escritura
		Cond, 
		Flags, 
		CondEx
	);

	flopr #(1) condreg( //Flop para hacer delay segun clock de CondEx y que se respenten los estados 
		clk, 
		reset, 
		CondEx, 
		CondExDelayed
	);
	//Las siguientes son las salidas del modulo condlogic que se pasan al datapath con los inputs del Main decoder FSM
	assign FlagWrite = FlagW & {2{CondEx}}; // Se escr
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

// DATAPATH MODIFICADO
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
	ALUControl,
	Shift
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
	input wire Shift;
	wire [31:0] srcBshifted; // LSL

	flopenr #(32) pcreg(
		clk, 
		reset, 
		PCWrite, 
		Result, 
		PC
	);
	

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
	
	
  mux3 #(32) srcamux(
    A,
    PC,
    ALUOut,
    ALUSrcA,
    SrcA
  );

	shifter sh(
		clk,
		reset,
		WriteData,
		Instr[11:7], 
		Instr[6:5], 
		srcBshifted
	);
	mux3 #(32) srcbmux(
		srcBshifted, 
		ExtImm, 
		32'd4, 
		ALUSrcB, 
		SrcB
	);
	// ALU
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
	mux2 #(32) aluresultmux(
		ALUOut, 
		SrcB, 
		Shift, 
		ALUResultOut
	); // LSL
endmodule


module alu (
	a,
	b,
  ALUControl,
  Result, 		//assign always block
  ALUFlags 		//explicit wire for assign with {}
);
	input [31:0] a,b,
  input [1:0] ALUControl,
  output reg [31:0] Result, 		
  output wire [3:0] ALUFlags 
  
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

module shifter(
	clk,
	rst,
	a,
	shamt,
	shtype,
	y
);
	input wire clk,           // Reloj
  input wire rst,           // Reset
	input wire [31:0] a,			// input
	input wire [4:0] shamt,		// shift cantidad
	input wire [1:0] shtype,		// 00=LSL, 01=LSR
	output reg [31:0] y // output

	always @(negedge clk) begin
		case (shtype)
			2'b00: y <= a << shamt;	// LSL
			2'b01: y <= a >> shamt;	// LSR
			default: y <= a;
		endcase
	end
endmodule


module Fp_clasifier(
	float, 
	snan, 
	qnan, 
	inf, 
	zero, 
	subnormal, 
	normal 
);
	input [15:0] float, 
	output snan, qnan, inf, zero, subnormal, normal 

	wire expOnes , expZeroes , sigZeroes ; 

	assign expOnes = &float[14:10];
	assign expZeroes = ~|float[14:10];
	assign sigZeroes = ~|float[9:0];

	assign snan = expOnes & ~sigZeroes & ~float[9];
	assign qnan = expOnes & float[9];
	assign inf = expOnes & sigZeroes;
	assign zero = expZeroes & sigZeroes;
	assign subnormal = expZeroes & ~sigZeroes;
	assign normal = ~expOnes &  ~expZeroes;

endmodule


module FP_mul(
	na, 
	nb,
	producto,
	snan, 
	qnan, 
	inf, 
	zero, 
	subnormal, 
	normal
);
	input [15:0] na, nb, 
	output wire [15:0] producto, 
	output reg snan, qnan, inf, zero, subnormal, normal

	wire Asnan, Aqnan, Ainf, Azero, Asubnormal, Anormal;
	wire Bsnan, Bqnan, Binf, Bzero, Bsubnormal, Bnormal;
	reg [15:0] productoTemp, product;
	reg [15:0] Signo;
	reg [21:0] partialResult; 
	reg [4:0] expa;
	reg [4:0] expb;
	parameter bias = 15; 
	reg [5:0] exponent;

	Fp_clasifier A(na, Asnan, Aqnan, Ainf, Azero, Asubnormal, Anormal);
	Fp_clasifier B(nb, Bsnan, Bqnan, Binf, Bzero, Bsubnormal, Bnormal);

	always @(*) begin
		{snan, qnan, inf, zero, subnormal, normal} = 6'b0;
		Signo = na[15] ^ nb[15];

		if (Asnan | Bsnan) begin
			productoTemp = Asnan ? na : nb;
			snan = 1;
		end else if (Aqnan | Bqnan) begin
			productoTemp = Aqnan ? na : nb;
			qnan = 1;
		end else if (Ainf | Binf) begin
			if (Azero | Bzero) begin
				productoTemp = {Signo, {5{1'b1}}, 1'b1, 9'b1};
				qnan = 1;
			end else begin
				productoTemp = {Signo, {5{1'b1}}, 10'b0};
				inf = 1;
			end
		end else if (Azero | Bzero || (Asubnormal & Bsubnormal)) begin
			productoTemp = {Signo, 15'b0};
			zero = 1;
		end else begin
			expa = na[14:10] - bias;
			expb = nb[14:10] - bias;
			exponent = expa + expb + bias; // Corregido para sumar el bias después de la suma de los exponentes
			partialResult = {1'b1, na[9:0]} * {1'b1, nb[9:0]};

			if (partialResult[21]) begin
				partialResult = partialResult >> 1;
				exponent = exponent + 1;
			end

			if (exponent > 30) begin // Corregido para considerar el rango correcto del exponente
				productoTemp = {Signo, 5'b11111, 10'b0};
				inf = 1;
			end else if (exponent < 1) begin // Corregido para el rango inferior del exponente
				productoTemp = {Signo, 15'b0};
				zero = 1;
			end else begin
				productoTemp = {Signo, exponent[4:0], partialResult[19:10]}; // Ajustado para seleccionar los bits correctos de partialResult
				normal = 1; 
			end
		end
	end

	assign producto = productoTemp; // Asigna productoTemp a la salida producto
endmodule

