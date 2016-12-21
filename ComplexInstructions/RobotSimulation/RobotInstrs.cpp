#include "RobotInstrs.h"

MoveForwardInsruction::MoveForwardInsruction(RobotSim &myRobot, int numSteps, TwoDimensionalAddress nextAd)
	: theRobot(myRobot)
	, numberOfSteps(numSteps)
	, nextAddr(nextAd)
{}

TwoDimensionalAddress MoveForwardInsruction::Execute(int registers[])
{
	theRobot.MoveRobotForward(numberOfSteps);

	return nextAddr;
}

MoveBackwardInsruction::MoveBackwardInsruction(RobotSim &myRobot, int numSteps, TwoDimensionalAddress nextAd)
	: theRobot(myRobot)
	, numberOfSteps(numSteps)
	, nextAddr(nextAd)
{}

TwoDimensionalAddress MoveBackwardInsruction::Execute(int registers[])
{
	theRobot.MoveRobotBackward(numberOfSteps);

	return nextAddr;
}

RotateAbsoluteInstruction::RotateAbsoluteInstruction(RobotSim &myRobot, int curAngle, TwoDimensionalAddress nextAd)
	: theRobot(myRobot)
	, angle(curAngle)
	, nextAddr(nextAd)
{}

TwoDimensionalAddress RotateAbsoluteInstruction::Execute(int registers[])
{
	theRobot.RotateRobotAbsolute(angle);

	return nextAddr;
}