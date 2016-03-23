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
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<ShooterRotation> shooterrotation;
	static std::shared_ptr<ShooterWheels> shooterwheels;
	static std::shared_ptr<ShooterActuator> shooteractuator;
	static std::shared_ptr<Shifter> shifter;

	static bool inverted;

	std::shared_ptr<SendableChooser> chooser;

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
