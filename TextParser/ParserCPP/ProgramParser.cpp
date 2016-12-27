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
	std::getline(infile, line);
	TwoDimensionalInstructionData curData = GetInstructionData(line);
	std::cout << curData.curX << " " << curData.curY << std::endl;

}

TwoDimensionalInstructionData ProgramParser::GetInstructionData(std::string instructionString)
{
	StringList instrList = splitBySpace(instructionString);
	int AddressX = std::atoi(instrList[0].c_str());
	int AddressY = std::atoi(instrList[1].c_str());
	std::string instructionName = instrList[2];

    TwoDimensionalInstructionData theData;
    theData.curX = AddressX;
    theData.curY = AddressY;

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