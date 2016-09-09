#include "InstructionType.h"


AddInstruction::AddInstruction(int inputAd1, int inputAd2, int outputAd, TwoDimensionalAddress nextAd)
	: inputAddr1(inputAd1) 
	, inputAddr2(inputAd2)
	, outputAddr(outputAd)
	, nextAddr(nextAd)
{}

TwoDimensionalAddress AddInstruction::Execute(int registers[])
{
	registers[outputAddr] = registers[inputAddr1] + registers[inputAddr2];
	return nextAddr;
}