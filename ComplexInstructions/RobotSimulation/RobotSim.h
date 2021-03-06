class RobotSim{
public:
	RobotSim();
	~RobotSim();

	void MoveRobotForward	(int steps);
	void MoveRobotBackward	(int steps);
	void RotateRobotAbsolute(int angle);
	void RotateRobotRelative(int angle);

	int getCurRobotX	() 	{return curRobotX; };
	int getCurRobotY	() 	{return curRobotY; };
	int getCurRobotAngle()	{return curRobotAngle; };

private:

	int curRobotX;
	int curRobotY;
	int curRobotAngle; // In Degrees

};