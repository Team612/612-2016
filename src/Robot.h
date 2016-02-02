#ifndef ROBOT_H
#define ROBOT_H

#include "OI.h"
#include "Subsystems/NavX.h"

class Robot: public IterativeRobot
{
private:

	//COMMAND
	Command* autonomousCommand;

	//LIVEWINDOW
	LiveWindow* lw;

	Robot* robot;
public:
	//CONSTRUCTOR
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestInit();
	void TestPeriodic();
	void DisabledInit();
	void DisabledPeriodic();
	//612 OBJECTS
	enum ROBOT_STATUS{
		NONE,
		ROBOTINIT,
		DISABLEDINIT,
		DISABLEDPERIODIC,
		AUTONOMOUSINIT,
		AUTONOMOUSPERIODIC,
		TELEOPINIT,
		TELEOPPERIODIC,
		TESTINIT,
		TESTPERIODIC
	};

	ROBOT_STATUS robot_status;
};
#endif
