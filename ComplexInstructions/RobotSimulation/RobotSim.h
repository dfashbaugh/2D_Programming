class RobotSim{
public:
	RobotSim();
	~RobotSim();

	int getCurRobotX() 	{return curRobotX; };
	int getCurRobotY() 	{return curRobotY; };

private:

	int curRobotX;
	int curRobotY;
	double curRobotAngle;

};