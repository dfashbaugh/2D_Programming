#include <iostream>
#include "../../BaseInstructions/InstructionType.h"

using namespace std;

#define REG_FILE_SIZE 255

void MakeAForLoop()
{
	int registers [REG_FILE_SIZE];
	TwoDimensionalInstruction* instructions[10][10]; 

	// Set Loop Control Variable
	instructions[0][0] = new SetInstruction(0, 20, TwoDimensionalAddress(0,1));

	// Set Counter
	instructions[0][1] = new SetInstruction(1, 0, TwoDimensionalAddress(0,2));

	// Set Incrementer
	instructions[0][2] = new SetInstruction(2, 1, TwoDimensionalAddress(0,3));

	// Branching instruction
	instructions[0][3] = new BranchIfGreaterInstruction(0,1, TwoDimensionalAddress(-1,-1), TwoDimensionalAddress(1,3));
	
	// Increment value by 1
	instructions[1][3] = new AddInstruction(1, 2, 1, TwoDimensionalAddress(0, 3));
	
	TwoDimensionalAddress myAddr(0,0);
	cout << myAddr.x << " " << myAddr.y << endl;
	while(myAddr.x >= 0 || myAddr.y >= 0)
	{
		myAddr =  instructions[myAddr.x][myAddr.y]->Execute(registers);
		cout << registers[1] << endl;
	}
	
	cout << "Done!" << endl;
}

int main(void)
{
	MakeAForLoop();
	return 0;
}