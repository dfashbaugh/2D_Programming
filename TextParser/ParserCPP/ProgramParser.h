#include "../../BaseInstructions/InstructionType.h"
#include <vector>
#include <string>

struct TwoDimensionalInstructionData{
	TwoDimensionalInstruction* Instruction;
	int curX;
	int curY;
};

struct InstructionConfigData{
	std::string InstrName;
	int InstrEnum;
};

typedef std::vector<TwoDimensionalInstructionData> InstructionList;
typedef std::vector<std::string> StringList;

typedef std::vector<InstructionConfigData> InstructionConfiguration;

class ProgramParser{
public:
	ProgramParser(std::string filePath, std::string configFile);
	~ProgramParser();

	InstructionList instrList;
	InstructionConfiguration configData;

	InstructionList GetInstructionList()	{return instrList; };
private:
	void LoadInstructionList(std::string filePath, std::string configFile);

	void LoadParserConfiguration(std::string configFile);

	TwoDimensionalInstructionData GetInstructionData(std::string instructionString);
	StringList splitBySpace(std::string splitString);
	
	TwoDimensionalInstruction* GetInstructionFromString(StringList &instructionStringList);

	TwoDimensionalInstruction* GetAddInstructionFromSplitString(StringList &instructionStringList);
	TwoDimensionalInstruction* GetSetInstructionFromSplitString(StringList &instructionStringList);
	TwoDimensionalInstruction* GetBranchIfGreaterInstructionFromSplitString(StringList &instructionStringList);
};