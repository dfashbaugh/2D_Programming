#include <iostream>
#include "../../BaseInstructions/InstructionType.h"

using namespace std;

#define REG_FILE_SIZE 255

void MakeAForLoop()
{
	int registers [REG_FILE_SIZE];
	TwoDimensionalInstruction* instructions[10][10]; 

	// Set Loop Control Variable
	registers[0] = 20;

	// Set Counter
	registers[1] = 0;

	// Set Incrementer
	registers[2] = 1;

	instructions[1][0] = new AddInstruction(1, 2, 1, TwoDimensionalAddress(0, 0));
	instructions[0][0] = new BranchIfGreaterInstruction(0,1, TwoDimensionalAddress(-1,-1), TwoDimensionalAddress(1,0));
	
	TwoDimensionalAddress myAddr(0,0);
	cout << myAddr.x << " " << myAddr.y << endl;
	while(myAddr.x >= 0 && myAddr.y >= 0)
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