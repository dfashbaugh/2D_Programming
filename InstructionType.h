// An address that points to a position in 2 Dimensional program space
struct TwoDimensionalAddress
{
	TwoDimensionalAddress(int inX, int inY) {x = inX; y = inY; };
	int x;
	int y;
};

// The type of instruction... Ultimately will be used to 
// "compile" a program made of Two Dimensional Instructions.
enum InstructionType
{
	add,
	subtract,
	multiply,
	divide,
	brIfGreater,
	brIfEqual
};

// A 2 dimensional program instruction. 
// Occupies an XY space and points to one or two more.
class TwoDimensionalInstruction
{
public:
	TwoDimensionalInstruction() {};
	virtual ~TwoDimensionalInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers []) = 0;
};

// Define a set of basic instructions
class AddInstruction : public TwoDimensionalInstruction
{
public:

	AddInstruction(int inputAd1, int inputAd2, int outputAd, TwoDimensionalAddress nextAd);
	virtual ~AddInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers[]);

private:
	int inputAddr1;
	int inputAddr2;
	int outputAddr;
	TwoDimensionalAddress nextAddr;
};

class SubInstruction : public TwoDimensionalInstruction
{
public:

	SubInstruction(int inputSub1, int inputSub2, int outputAd, TwoDimensionalAddress nextAd);
	virtual ~SubInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers []);

private:
	int inputAddr1;
	int inputAddr2;
	int outputAddr;
	TwoDimensionalAddress nextAddr;
};

class MultInstruction : public TwoDimensionalInstruction
{
public:

	MultInstruction(int inputMult1, int inputMult2, int outputAd, TwoDimensionalAddress nextAd);
	virtual ~MultInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers []);

private:
	int inputAddr1;
	int inputAddr2;
	int outputAddr;
	TwoDimensionalAddress nextAddr;
};

class DivInstruction : public TwoDimensionalInstruction
{
public:

	DivInstruction(int inputDiv1, int inputDiv2, int outputAd, TwoDimensionalAddress nextAd);
	virtual ~DivInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers []);

private:
	int inputAddr1;
	int inputAddr2;
	int outputAddr;
	TwoDimensionalAddress nextAddr;
};

class BranchIfGreaterInstruction : public TwoDimensionalInstruction
{
public:

	BranchIfGreaterInstruction(int inputBr1, int inputBr2, TwoDimensionalAddress nextAd, TwoDimensionalAddress branchAd);
	virtual ~BranchIfGreaterInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers []);

private:
	int inputAddr1;
	int inputAddr2;
	TwoDimensionalAddress nextAddr;
	TwoDimensionalAddress branchAddr;
};