#include "Robot.h"
#include <Commands/Autonomous/Sequences/HorizontalFind.h>
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/DriveSet.h"
#include "Commands/Autonomous/Autonomous.h"
#include "Commands/Autonomous/Sequences/AutoAlign.h"
#include <SmartDashboard/SmartDashboard.h>

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterWheels> Robot::shooterwheels;
std::shared_ptr<ShooterRotation> Robot::shooterrotation;
std::shared_ptr<Shifter> Robot::shifter;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Vision> Robot::vision;

bool Robot::inverted;

//#define BROWNOUT

void Robot::RobotInit()
{
	RobotMap::init();

	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	vision.reset(new Vision());
	shifter.reset(new Shifter());
	oi.reset(new OI());

	RobotMap::NavX->ZeroYaw();
	printf("Zeroed Yaw in init!\n");
	InitSmartDashboard();

	autonomousCommand.reset(new Autonomous());
	drivejoystick.reset(new DriveJoystick());
	align.reset(new AutoAlign(HorizontalFind::LEFT));
}

void Robot::DisabledInit()
{

}

void
Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();

#ifdef BROWNOUT
	if(DriverStation::GetInstance().IsSysBrownedOut())
		printf("ERROR: System brownout!\n");
	}
#endif
}

void Robot::AutonomousInit()
{
	shifter->Set(Shifter::LOW);

	RobotMap::NavX->Reset();
	printf("Info: Reset NavX\n");

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	vision->PullValues(); //Keep this above the scheduler
	Scheduler::GetInstance()->Run();
	PeriodicSmartDashboard();

#ifdef BROWNOUT
	if(DriverStation::GetInstance().IsSysBrownedOut())
		printf("ERROR: System brownout!\n");
	}
#endif
}

void Robot::TeleopInit()
{
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	RobotMap::NavX->Reset();
	printf("Info: Reset NavX\n");

	drivejoystick->Start();
	shifter->Set(Shifter::LOW);
}



void Robot::TeleopPeriodic()
{
	vision->PullValues(); //Keep this above the scheduler
	Scheduler::GetInstance()->Run();
    PeriodicSmartDashboard();

#ifdef BROWNOUT
	if(DriverStation::GetInstance().IsSysBrownedOut())
		printf("ERROR: System brownout!\n");
	}
#endif
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
	lw->Run();
	if(DriverStation::GetInstance().IsBrownedOut())
	{
		printf("ERROR: System brownout!\n");
	}
}

void Robot::InitSmartDashboard()
{

	SmartDashboard::PutNumber("Shooter Angle", 0.0);

	//Commands for debugging
	shooterrotation->SmartDashboardOutput();
	SmartDashboard::PutData("Stop Drivetrain", new DriveSet(0.0f, 0.0f));
	//Auto Align
	SmartDashboard::PutData("Auto Right", new AutoAlign(HorizontalFind::Direction::RIGHT));
	SmartDashboard::PutData("Auto Left", new AutoAlign(HorizontalFind::Direction::LEFT));

	SmartDashboard::PutNumber("dP", 0.004);
	SmartDashboard::PutNumber("dI", 0);
	SmartDashboard::PutNumber("dD", 0);
}

void Robot::PeriodicSmartDashboard()
{
	Robot::shooterrotation->SmartDashboardOutput();

	SmartDashboard::PutNumber("Shooter Absolute Encoder", RobotMap::shooterPotentiometer->GetVoltage());
	SmartDashboard::PutNumber("Shooter Absolute Encoder Rounded", RobotMap::shooterPotentiometer->GetVoltageRound());


	//SmartDashboard::PutNumber("Shooter Actuator Motor", (double) RobotMap::shooterActuatorMotor->Get());

	SmartDashboard::PutBoolean("Inverted Controls", inverted);

	SmartDashboard::PutNumber("Left Shifter", RobotMap::shifterL->Get());
	SmartDashboard::PutNumber("Right Shifter", RobotMap::shifterR->Get());

	//SmartDashboard::PutNumber("Rotation Speed", RobotMap::shooterRotateMotor->Get());

	SmartDashboard::PutNumber("NavX Pitch (in degrees)", RobotMap::NavX->GetPitch());
	SmartDashboard::PutNumber("NavX Roll (in degrees)", RobotMap::NavX->GetRoll());
	SmartDashboard::PutNumber("NavX Yaw", (float) (RobotMap::NavX->GetYaw()));
}

START_ROBOT_CLASS(Robot);
