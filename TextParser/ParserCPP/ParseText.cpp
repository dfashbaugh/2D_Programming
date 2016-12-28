#include <iostream>
#include "ProgramParser.h"

using namespace std;

int main(void)
{
	ProgramParser theParser("testProgram.2dp");

	InstructionList myList = theParser.GetInstructionList();

	int registers [255];
	TwoDimensionalInstruction* instructions[10][10]; 

	for(int i = 0; i < myList.size(); i++)
	{
		instructions[myList[i].curX][myList[i].curY] = myList[i].Instruction;
	}
	
	TwoDimensionalAddress myAddr(0,0);
	while(myAddr.x >= 0 && myAddr.y >= 0)
	{
		myAddr =  instructions[myAddr.x][myAddr.y]->Execute(registers);
		cout << registers[0] << " " << registers[1] << " " << registers[2] << endl;
	}
	
	cout << "Done!" << endl;

	return 0;
}