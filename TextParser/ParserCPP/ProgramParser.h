#include "../../BaseInstructions/InstructionType.h"
#include <vector>
#include <string>

struct TwoDimensionalInstructionData{
	TwoDimensionalInstruction* Instruction;
	int curX;
	int curY;
};

typedef std::vector<TwoDimensionalInstructionData> InstructionList;
typedef std::vector<std::string> StringList;

class ProgramParser{
public:
	ProgramParser(std::string filePath, std::string configFile);
	~ProgramParser();

	InstructionList instrList;

	InstructionList GetInstructionList()	{return instrList; };
private:
	void LoadInstructionList(std::string filePath, std::string configFile);
	TwoDimensionalInstructionData GetInstructionData(std::string instructionString);
	StringList splitBySpace(std::string splitString);
	
	TwoDimensionalInstruction* GetInstructionFromString(StringList &instructionStringList);

	TwoDimensionalInstruction* GetAddInstructionFromSplitString(StringList &instructionStringList);
	TwoDimensionalInstruction* GetSetInstructionFromSplitString(StringList &instructionStringList);
	TwoDimensionalInstruction* GetBranchIfGreaterInstructionFromSplitString(StringList &instructionStringList);
};