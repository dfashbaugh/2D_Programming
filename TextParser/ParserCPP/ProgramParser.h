#include "../../BaseInstructions/InstructionType.h"
#include <vector>
#include <string>

struct TwoDimensionalInstructionData{
	TwoDimensionalInstruction* Instruction;
	int curX;
	int curY;
};

typedef std::vector<TwoDimensionalInstructionData> InstructionList;

class ProgramParser{
public:
	ProgramParser(std::string filePath);
	~ProgramParser();

	InstructionList instrList;

private:
	void LoadInstructionList(std::string filePath);
};