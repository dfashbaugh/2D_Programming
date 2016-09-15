#include <iostream>
#include "InstructionType.h"

using namespace std;

void PrintRegisters(int registers[], int regFileSize)
{
	for(int i = 0; i < regFileSize; i++)
	{
		cout << i << " " << registers[i] << endl;
	}
}

void TestCommands()
{
	// Example Functional Execution Codee
	int registers [255];
	for(int i = 0; i<255; i++)
	{
		registers[i] = 0;
	}

	registers[0] = 3;

	TwoDimensionalInstruction* instructions[10][10];
	instructions[0][0] = new AddInstruction(0, 0, 1, TwoDimensionalAddress(0,1));
	instructions[0][1] = new SubInstruction(1, 0, 1, TwoDimensionalAddress(0,1));

	TwoDimensionalAddress myAddr(0,0);

	 myAddr = instructions[myAddr.x][myAddr.y]->Execute(registers);
	 myAddr = instructions[myAddr.x][myAddr.y]->Execute(registers);

	 PrintRegisters(registers, 255);
}

int main(void)
{
	cout << "Test Beginning" << endl;

	TestCommands();

	return 0;
}