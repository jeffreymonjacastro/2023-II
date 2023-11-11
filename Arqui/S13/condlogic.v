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
	wire CondEx, CondExDelayed; // DELAY


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

	// Delay writing flags until ALUWB state
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