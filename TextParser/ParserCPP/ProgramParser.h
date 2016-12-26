#include "../../BaseInstructions/InstructionType.h"
#include <vector>

typedef std::vector<TwoDimensionalInstruction> InstructionList;

class ProgramParser{
public:
	ProgramParser();
	~ProgramParser();

	InstructionList instrList;
};