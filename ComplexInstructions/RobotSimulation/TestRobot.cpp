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
	instructions[0][0] = new MoveForwardInsruction(robot, 20, TwoDimensionalAddress(0,1));
	instructions[0][1] = new MoveBackwardInsruction(robot, 10, TwoDimensionalAddress(0,2));
	instructions[0][2] = new RotateAbsoluteInstruction(robot, 270, TwoDimensionalAddress(0, 3));
	instructions[0][3] = new MoveForwardInsruction(robot, 10, TwoDimensionalAddress(0,4));
	instructions[0][4] = new RotateRelativeInstruction(robot, 20, TwoDimensionalAddress(0,5));
	instructions[0][5] = new MoveForwardInsruction(robot, 10, TwoDimensionalAddress(0, -1));

	TwoDimensionalAddress myAddr(0,0);
	while(myAddr.x >= 0 && myAddr.y >= 0)
	{
		myAddr = instructions[myAddr.x][myAddr.y]->Execute(registers);
		cout << "Robot X: " << robot.getCurRobotX();
		cout << " Robot Y: " << robot.getCurRobotY();
		cout << " Robot Angle: " << robot.getCurRobotAngle() << endl;
	}
	
	cout << "Done!" << endl;

	return 0;
}