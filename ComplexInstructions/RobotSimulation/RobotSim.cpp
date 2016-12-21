#include "RobotSim.h"
#include <math.h>

RobotSim::RobotSim()
	: curRobotX(0)
	, curRobotY(0)
	, curRobotAngle(0)
{

}

RobotSim::~RobotSim()
{}

void RobotSim::MoveRobotForward(int steps)
{
	double angleInRadians = (curRobotAngle*3.141)/180.0;

	int furtherX = steps * cos(angleInRadians);
	int furtherY = steps * sin(angleInRadians);

	curRobotX = curRobotX + furtherX;
	curRobotY = curRobotY + furtherY;
}

void RobotSim::MoveRobotBackward(int steps)
{
	double angleInRadians = (curRobotAngle*3.141)/180.0;

	int furtherX = -1 * steps * cos(angleInRadians);
	int furtherY = -1 * steps * sin(angleInRadians);

	curRobotX = curRobotX + furtherX;
	curRobotY = curRobotY + furtherY;
}

void RobotSim::RotateRobotAbsolute(int angle)
{
	curRobotAngle = angle;
}

void RobotSim::RotateRobotRelative(int angle)
{
	curRobotAngle += angle;
}