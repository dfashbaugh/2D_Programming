#include "ProgramParser.h"
#include <fstream>
#include <iostream>
#include <sstream>


ProgramParser::ProgramParser(std::string filePath, std::string configFile)
{
	LoadInstructionList(filePath, configFile);
}

ProgramParser::~ProgramParser()
{
	
}

void ProgramParser::LoadInstructionList(std::string filePath, std::string configFile)
{
	LoadParserConfiguration(configFile);

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
	std::string instrName = instructionStringList[2];
	int instructionNumber = 0;

	for(auto dat : configData)
	{
		if(instrName == dat.InstrName)
		{
			instructionNumber = dat.InstrEnum;
		}
	}

	TwoDimensionalInstruction* myInstr;

	// If it is a basic instruction, get it here
	if(instructionNumber == addInstr)
	{
		myInstr = GetAddInstructionFromSplitString(instructionStringList);
	}
	else if(instructionNumber == setInstr)
	{
		myInstr = GetSetInstructionFromSplitString(instructionStringList);
	}
	else if(instructionNumber == brgrInstr)
	{
		myInstr = GetBranchIfGreaterInstructionFromSplitString(instructionStringList);
	}
	else if(instructionNumber == multInstr)
	{
		myInstr = GetMultiplyInstructionFromSplitString(instructionStringList);
	}
	else if(instructionNumber == divInstr)
	{
		myInstr = GetDivideInstructionFromSplitString(instructionStringList);
	}
	else if(instructionNumber == nopInstr)
	{
		myInstr = GetNOPInstructionFromSplitString(instructionStringList);
	}

	// If non-basic instruction, get it here

	return myInstr;
}

void ProgramParser::LoadParserConfiguration(std::string configFile)
{
	std::ifstream infile(configFile);
	std::string line;

	configData.clear();
	while(std::getline(infile, line))
	{
		if(line.length() > 0)
		{
			StringList myList = splitBySpace(line);
			InstructionConfigData newConfigData;
			newConfigData.InstrName = myList.at(0);
			newConfigData.InstrEnum = std::atoi(myList.at(1).c_str());

			configData.push_back(newConfigData);
		}
	}
}

TwoDimensionalInstruction* ProgramParser::GetAddInstructionFromSplitString(StringList &instructionStringList)
{
	std::cout << "Add Type" << std::endl;
	int Reg1 = std::atoi(instructionStringList[3].c_str());
	int Reg2 = std::atoi(instructionStringList[4].c_str());
	int RegDest = std::atoi(instructionStringList[5].c_str());
	int destX = std::atoi(instructionStringList[6].c_str());
	int destY = std::atoi(instructionStringList[7].c_str());
	return new AddInstruction(Reg1, Reg2, RegDest, TwoDimensionalAddress(destX, destY));
}

TwoDimensionalInstruction* ProgramParser::GetSetInstructionFromSplitString(StringList &instructionStringList)
{
	std::cout << "Set Type" << std::endl;
	int Reg = std::atoi(instructionStringList[3].c_str());
	int value = std::atoi(instructionStringList[4].c_str());
	int destX = std::atoi(instructionStringList[5].c_str());
	int destY = std::atoi(instructionStringList[6].c_str());

	return new SetInstruction(Reg, value, TwoDimensionalAddress(destX, destY));
}

TwoDimensionalInstruction* ProgramParser::GetBranchIfGreaterInstructionFromSplitString(StringList &instructionStringList)
{
	std::cout << "Branch if Greater Type" << std::endl;
	int Reg1 = std::atoi(instructionStringList[3].c_str());
	int Reg2 = std::atoi(instructionStringList[4].c_str());
	int brDestX = std::atoi(instructionStringList[5].c_str());
	int brDestY = std::atoi(instructionStringList[6].c_str());
	int dDestX = std::atoi(instructionStringList[7].c_str());
	int dDestY = std::atoi(instructionStringList[8].c_str());

	return new BranchIfGreaterInstruction(Reg1,Reg2, TwoDimensionalAddress(dDestX, dDestY), TwoDimensionalAddress(brDestX,brDestY));
}

TwoDimensionalInstruction* ProgramParser::GetMultiplyInstructionFromSplitString(StringList &instructionStringList)
{
	std::cout << "Multiply Type" << std::endl;
	int Reg1 = std::atoi(instructionStringList[3].c_str());
	int Reg2 = std::atoi(instructionStringList[4].c_str());
	int RegDest = std::atoi(instructionStringList[5].c_str());
	int destX = std::atoi(instructionStringList[6].c_str());
	int destY = std::atoi(instructionStringList[7].c_str());
	return new MultInstruction(Reg1, Reg2, RegDest, TwoDimensionalAddress(destX, destY));
}

TwoDimensionalInstruction* ProgramParser::GetDivideInstructionFromSplitString(StringList &instructionStringList)
{
	std::cout << "Divide Type" << std::endl;
	int Reg1 = std::atoi(instructionStringList[3].c_str());
	int Reg2 = std::atoi(instructionStringList[4].c_str());
	int RegDest = std::atoi(instructionStringList[5].c_str());
	int destX = std::atoi(instructionStringList[6].c_str());
	int destY = std::atoi(instructionStringList[7].c_str());
	return new DivInstruction(Reg1, Reg2, RegDest, TwoDimensionalAddress(destX, destY));
}

TwoDimensionalInstruction* ProgramParser::GetNOPInstructionFromSplitString(StringList &instructionStringList)
{
	std::cout << "Nop Type" << std::endl;
	int destX = std::atoi(instructionStringList[3].c_str());
	int destY = std::atoi(instructionStringList[4].c_str());
	return new NOpInstruction(TwoDimensionalAddress(destX, destY));
}
