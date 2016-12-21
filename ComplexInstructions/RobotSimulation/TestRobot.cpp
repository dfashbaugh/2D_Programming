#include <iostream>
#include "RobotInstrs.h"

using namespace std;

int main(void)
{
	cout << "Test Beginning" << endl;

	RobotSim robot;

	int registers [10];
	TwoDimensionalInstruction* instructions[10][10]; 

	// Set Loop Control Variable
	instructions[0][0] = new MoveForwardInsruction(robot, 20, TwoDimensionalAddress(0,-1));

	TwoDimensionalAddress myAddr(0,0);
	cout << myAddr.x << " " << myAddr.y << endl;
	while(myAddr.x >= 0 && myAddr.y >= 0)
	{
		myAddr = instructions[myAddr.x][myAddr.y]->Execute(registers);
		cout << "Instruction Done" << endl;
		cout << myAddr.x << " " << myAddr.y << endl;
	}
	
	cout << robot.getCurRobotX() << " " << robot.getCurRobotY() << endl;
	cout << "Done!" << endl;

	return 0;
}