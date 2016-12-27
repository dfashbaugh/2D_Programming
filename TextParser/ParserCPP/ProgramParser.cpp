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
	GetInstructionData(line);
}

TwoDimensionalInstructionData ProgramParser::GetInstructionData(std::string instructionString)
{
	splitBySpace(instructionString);
    TwoDimensionalInstructionData theData;

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
        std::cout << "Substring: " << sub << " size: " << sub.length() << std::endl;
    } while (iss);

    return myList;
}