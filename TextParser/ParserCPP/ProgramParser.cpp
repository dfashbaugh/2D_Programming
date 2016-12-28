#include "ProgramParser.h"
#include <fstream>
#include <iostream>
#include <sstream>


ProgramParser::ProgramParser(std::string filePath)
{
	LoadInstructionList(filePath);
}

ProgramParser::~ProgramParser()
{
	
}

void ProgramParser::LoadInstructionList(std::string filePath)
{
	std::ifstream infile(filePath);
	std::string line;

	instrList.clear();
	while(std::getline(infile, line))
	{
		if(line.length() > 0)
		{
			TwoDimensionalInstructionData curData = GetInstructionData(line);
			instrList.push_back(curData);
		}
	}
	

}

TwoDimensionalInstructionData ProgramParser::GetInstructionData(std::string instructionString)
{
	StringList instrList = splitBySpace(instructionString);
	int AddressX = std::atoi(instrList[0].c_str());
	int AddressY = std::atoi(instrList[1].c_str());

    TwoDimensionalInstructionData theData;
    theData.curX = AddressX;
    theData.curY = AddressY;
    theData.Instruction = GetInstructionFromString(instrList);

    return theData;
}

StringList ProgramParser::splitBySpace(std::string splitString)
{
	StringList myList;

	std::istringstream iss(splitString);
	do
    {
        std::string sub;
        iss >> sub;
        if(sub.length() > 0)
        {
        	myList.push_back(sub);
        }
        //std::cout << "Substring: " << sub << " size: " << sub.length() << std::endl;
    } while (iss);

    return myList;
}

TwoDimensionalInstruction* ProgramParser::GetInstructionFromString(StringList &instructionStringList)
{
	std::string AddInstrTypeName = "Add";
	std::string SetInstrTypeName = "Set";
	std::string BranchGreaterTypeName = "BrGr";

	std::string instrName = instructionStringList[2];

	TwoDimensionalInstruction* myInstr;

	if(instrName == AddInstrTypeName)
	{
		std::cout << "Add Type" << std::endl;
		int Reg1 = std::atoi(instructionStringList[3].c_str());
		int Reg2 = std::atoi(instructionStringList[4].c_str());
		int RegDest = std::atoi(instructionStringList[5].c_str());
		int destX = std::atoi(instructionStringList[6].c_str());
		int destY = std::atoi(instructionStringList[7].c_str());
		myInstr = new AddInstruction(Reg1, Reg2, RegDest, TwoDimensionalAddress(destX, destY));
	}
	else if(instrName == SetInstrTypeName)
	{
		std::cout << "Set Type" << std::endl;
		int Reg = std::atoi(instructionStringList[3].c_str());
		int value = std::atoi(instructionStringList[4].c_str());
		int destX = std::atoi(instructionStringList[5].c_str());
		int destY = std::atoi(instructionStringList[6].c_str());

		myInstr = new SetInstruction(Reg, value, TwoDimensionalAddress(destX, destY));
	}
	else if(instrName == BranchGreaterTypeName)
	{
		std::cout << "Branch if Greater Type" << std::endl;
		int Reg1 = std::atoi(instructionStringList[3].c_str());
		int Reg2 = std::atoi(instructionStringList[4].c_str());
		int brDestX = std::atoi(instructionStringList[5].c_str());
		int brDestY = std::atoi(instructionStringList[6].c_str());
		int dDestX = std::atoi(instructionStringList[7].c_str());
		int dDestY = std::atoi(instructionStringList[8].c_str());

		myInstr = new BranchIfGreaterInstruction(Reg1,Reg2, TwoDimensionalAddress(dDestX, dDestY), TwoDimensionalAddress(brDestX,brDestY));
	}

	return myInstr;
}






