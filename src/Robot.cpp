#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Robot.h"
#include "RobotMap.h"


void Robot::RobotInit()
{
	CommandBase::init(); // Constructor for CommandBase
	lw = LiveWindow::GetInstance();
	robot = this;
	autonomousCommand = NULL;

}

void Robot::DisabledInit()
{
	robot_status = DISABLEDINIT; // Makes the status equal DISABLEDINIT
}

void Robot::DisabledPeriodic()
{
	if (robot_status != DISABLEDPERIODIC)
		robot_status = DISABLEDPERIODIC;
}

void Robot::AutonomousInit()
{
	robot_status = AUTONOMOUSINIT; // Makes the status equal AUTONOMOUSINIT
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	if (robot_status != AUTONOMOUSPERIODIC) // Makes the status equal AUTONOMOUSPERIODIC
		robot_status = AUTONOMOUSPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	printf("Teleopinit\n");
	robot_status = TELEOPINIT; // Makes the status equal TELEOPINIT
	/*
	 * This makes sure that the autonomous stops running when
	 * teleop starts running. If you want the autonomous to
	 * continue until interrupted by another command, remove
	 * this line or comment it out.
	 */
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	if (robot_status != TELEOPPERIODIC) // Makes the status equal TELEOPPERIODIC
		robot_status = TELEOPPERIODIC;
	Scheduler::GetInstance()->Run();
	lw->Run();
}

void Robot::TestInit()
{
	robot_status = TESTINIT; // Makes the status equal TESTINIT
	printf("lel what are you even doing here scrub?\n");
}
void Robot::TestPeriodic()
{
	if (robot_status != TESTPERIODIC) // Makes the status equal TESTPERIODIC
		robot_status = TESTPERIODIC;
	lw->Run();
	//float val = joystick->GetRawAxis(5); //Takes input from joystick
	//firstTalon->Set(val); //Gives joystick input to first talon
	//secondTalon->Set(val);

}


START_ROBOT_CLASS(Robot);
