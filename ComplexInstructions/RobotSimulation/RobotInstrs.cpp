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