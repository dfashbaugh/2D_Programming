#include "ProgramParser.h"
#include <fstream>


ProgramParser::ProgramParser(std::string filePath)
{
	std::ifstream infile(filePath);
	std::string line;
	std::getline(infile, line);
}

ProgramParser::~ProgramParser()
{
	
}