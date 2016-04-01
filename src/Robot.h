#ifndef _ROBOT_H
#define _ROBOT_H

#include <WPILib.h>
#include <Commands/Command.h>
#include "RobotMap.h"
#include <LiveWindow/LiveWindow.h>

#include <Subsystems/Drivetrain.h>
#include <Subsystems/ShooterWheels.h>
#include <Subsystems/ShooterRotation.h>
#include <Subsystems/ShooterActuator.h>
#include <Subsystems/Shifter.h>
#include <Subsystems/Arm.h>

#include <OI.h>

class Robot: public IterativeRobot
{
private:
	void InitSmartDashboard();
	void PeriodicSmartDashboard();
public:
	enum Defense {PORTCULLIS, CHEVAL_DE_FRISE, MOAT, RAMPARTS, DRAW_BRIDGE, SALLY_PORT, ROCK_WALL, ROUGH_TERRAIN, LOW_BAR, NONE};
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> drivejoystick;
	std::unique_ptr<Command> autowheels;
	std::unique_ptr<Command> armJoystick;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<ShooterRotation> shooterrotation;
	static std::shared_ptr<ShooterWheels> shooterwheels;
	static std::shared_ptr<ShooterActuator> shooteractuator;
	static std::shared_ptr<Shifter> shifter;
	static std::shared_ptr<Arm> arm;

	static bool inverted;

	static float robot_yaw;

	std::shared_ptr<SendableChooser> chooser;

	//std::shared_ptr<CameraServer> server;

	//CameraServer* server = CameraServer::GetInstance();
	Timer * time = new Timer();

	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
