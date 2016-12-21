#include "../../BaseInstructions/InstructionType.h"
#include "RobotSim.h"

class MoveForwardInsruction : public TwoDimensionalInstruction
{
public:
	
	MoveForwardInsruction(RobotSim &myRobot, int numSteps, TwoDimensionalAddress nextAd);
	virtual ~MoveForwardInsruction() {};

	virtual TwoDimensionalAddress Execute(int registers[]);

private:
	RobotSim &theRobot;
	int numberOfSteps;
	TwoDimensionalAddress nextAddr;
};

class MoveBackwardInsruction : public TwoDimensionalInstruction
{
public:
	
	MoveBackwardInsruction(RobotSim &myRobot, int numSteps, TwoDimensionalAddress nextAd);
	virtual ~MoveBackwardInsruction() {};

	virtual TwoDimensionalAddress Execute(int registers[]);

private:
	RobotSim &theRobot;
	int numberOfSteps;
	TwoDimensionalAddress nextAddr;
};

class RotateAbsoluteInstruction : public TwoDimensionalInstruction
{
public:
	
	RotateAbsoluteInstruction(RobotSim &myRobot, int curAngle, TwoDimensionalAddress nextAd);
	virtual ~RotateAbsoluteInstruction() {};

	virtual TwoDimensionalAddress Execute(int registers[]);

private:
	RobotSim &theRobot;
	int angle;
	TwoDimensionalAddress nextAddr;
};