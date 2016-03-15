#ifndef _ROBOT_H
#define _ROBOT_H

#include <WPILib.h>
#include <Commands/Command.h>
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/ShooterWheels.h"
#include "Subsystems/ShooterRotation.h"
#include "Subsystems/Vision.h"
#include "Subsystems/ShooterLever.h"
#include "Subsystems/Shifter.h"

#include "OI.h"

class Robot: public IterativeRobot
{
private:
	void InitSmartDashboard();
	void PeriodicSmartDashboard();
public:
	std::unique_ptr<Command> autonomousCommand;
	std::unique_ptr<Command> invertcontrols;
	//std::unique_ptr<Command> drivejoystick;
	//std::unique_ptr<Command> armmove;
	std::unique_ptr<Command> autowheels;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	static std::shared_ptr<Drivetrain> drivetrain;
	static std::shared_ptr<ShooterRotation> shooterrotation;
	static std::shared_ptr<ShooterWheels> shooterwheels;
	static std::unique_ptr<Vision> vision;
	static std::shared_ptr<ShooterLever> shooterlever;
	static std::shared_ptr<Shifter> shifter;
	static std::shared_ptr<CameraServer> server;
	//NavX *navx;
	//CameraServer* server = CameraServer::GetInstance();
	static bool inverted;

	static std::shared_ptr<SendableChooser> autoChooser;

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
