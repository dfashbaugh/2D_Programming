#include "RobotInstrs.h"

MoveForwardInsruction::MoveForwardInsruction(RobotSim &myRobot, int inputValue, TwoDimensionalAddress nextAd)
	: theRobot(myRobot)
	, inputVal(inputValue)
	, nextAddr(nextAd)
{}

TwoDimensionalAddress MoveForwardInsruction::Execute(int registers[])
{

	return nextAddr;
}