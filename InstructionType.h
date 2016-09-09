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