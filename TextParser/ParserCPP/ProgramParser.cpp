#include "ProgramParser.h"
#include <fstream>
#include <iostream>


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
	std::cout << line << std::endl;
}