#include <Commands/Autonomous/Sequences/HorizontalFind.h>
#include <Commands/Shooter/ShooterControl.h>
#include "Robot.h"

#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/DriveSet.h"
#include "Commands/Autonomous/Autonomous.h"
#include "Commands/Autonomous/Sequences/AutoAlign.h"
#include "Commands/Drive/DriveDistance.h"
#include <SmartDashboard/SmartDashboard.h>

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterWheels> Robot::shooterwheels;
std::shared_ptr<ShooterRotation> Robot::shooterrotation;
std::shared_ptr<Pneumatics> Robot::pneumatics;
std::shared_ptr<Shifter> Robot::shifter;
std::unique_ptr<OI> Robot::oi;
std::shared_ptr<Vision> Robot::vision;

bool Robot::inverted;
bool Robot::SPYBOT;

//#define BROWNOUT

/*
 * robot_yaw exists so we don't have to worry about calibrating the NavX
 * before every match. We just get the initial yaw and compare the current
 * yaw with the initial. We only need to know if we're off by whatever
 * amount.
 * TODO: Test and use the method ZeroYaw()
 */


void Robot::RobotInit()
{
	RobotMap::init();

	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	vision.reset(new Vision());
	pneumatics.reset(new Pneumatics());
	shifter.reset(new Shifter());
	oi.reset(new OI());

	RobotMap::NavX.get()->ZeroYaw();
	printf("Zeroed Yaw in init!\n");
	InitSmartDashboard();

	//SmartDashboard::PutData("FireShooter", new FireShooter());
	//SmartDashboard::PutData("Autonomous", new Autonomous());

	// instantiate the command used for the autonomous period
	autonomousCommand.reset(new Autonomous());
	drivejoystick.reset(new DriveJoystick());
	align.reset(new AutoAlign(HorizontalFind::LEFT));

	//Jetson autostartup
	if(RobotMap::jetsonI.get()->Get())
		std::printf("Nvidia TX1 on\n");
	else
	{
		std::printf("Nvidia TX1 off\n Attempting to turn on\n");
		RobotMap::jetsonO.get()->Pulse(0.0016);
		RobotMap::jetsonO.get()->Pulse(0.0016);
	}
	SPYBOT = SmartDashboard::GetBoolean("Spy bot", false);
}

void Robot::DisabledInit()
{
	//SPYBOT = SmartDashboard::GetBoolean("Spy bot", false);
}

void
Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();

#ifdef BROWNOUT
	if(DriverStation::GetInstance().IsSysBrownedOut())
	{
		printf("ERROR: System brownout!\n");
	}
#endif
}

void Robot::AutonomousInit()
{
	SPYBOT = SmartDashboard::GetBoolean("Spy bot", false); //set this on the dashboard yo!
	shifter->Set(Shifter::LOW);

	RobotMap::NavX.get()->Reset();
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
	{
		printf("ERROR: System brownout!\n");
	}
#endif
}

void Robot::TeleopInit()
{
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	RobotMap::NavX.get()->Reset();
	printf("Info: Reset NavX\n");

	drivejoystick->Start();
	shifter->Set(Shifter::LOW);
	//shooterrotation->PIDEnable(true);

}



void Robot::TeleopPeriodic()
{
	vision->PullValues(); //Keep this above the scheduler
	Scheduler::GetInstance()->Run();
    PeriodicSmartDashboard();

#ifdef BROWNOUT
	if(DriverStation::GetInstance().IsSysBrownedOut())
	{
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
	if(DriverStation::GetInstance().IsSysBrownedOut())
	{
		printf("ERROR: System brownout!\n");
	}
}

void Robot::InitSmartDashboard()
{
	//ShooterPID
//	SmartDashboard::PutNumber("P", 0.0);
//	SmartDashboard::PutNumber("I", 0.0);
//	SmartDashboard::PutNumber("D", 0.0);
	SmartDashboard::PutNumber("Shooter Angle", 0.0);

	//Commands for debugging
	shooterrotation->SmartDashboardOutput();
	SmartDashboard::PutData("Stop Drivetrain", new DriveSet(0.0f, 0.0f));
	SmartDashboard::PutData("Drive Joystick", new DriveJoystick());
	SmartDashboard::PutData("Drive Distance", new DriveDistance(240));
	//Auto Align
	/*
		SmartDashboard::PutData("Auto Right", new AutoAlign(HorizontalFind::Direction::RIGHT));
		SmartDashboard::PutData("Auto Left", new AutoAlign(HorizontalFind::Direction::LEFT));

++	//autonomous
	autoChooser->AddObject("Low Bar", new SimpleAutonomous(6, 0.8f));
	autoChooser->AddObject("Other Defense", new SimpleAutonomous(7, 0.9f));

	SmartDashboard::PutData("Autonomous Defense Chooser", autoChooser.get());*/

	SmartDashboard::PutNumber("dP", 0.004);
	SmartDashboard::PutNumber("dI", 0);
	SmartDashboard::PutNumber("dD", 0);
}

void Robot::PeriodicSmartDashboard()
{
	Robot::shooterrotation->SmartDashboardOutput();

	SmartDashboard::PutNumber("Shooter Absolute Encoder", RobotMap::shooterAbsEncoder.get()->GetVoltage());
	SmartDashboard::PutNumber("Shooter Absolute Encoder Rounded", RobotMap::shooterAbsEncoder.get()->GetVoltageRound());

	//SmartDashboard::PutBoolean("Shooter Actuator Limit Switch", RobotMap::shooterActuatorLSwitch.get()->Get());
	//SmartDashboard::PutBoolean("Second Shooter Actuator Limit Switch", RobotMap::shooterActuatorLSwitch2.get()->Get());
	//std::printf("Shooter Actuator Limit Switch: %i\n", (int) RobotMap::shooterActuatorLSwitch.get()->Get());
	//std::printf("Second Shooter Actuator Limit Switch: %i\n", (int) RobotMap::shooterActuatorLSwitch.get()->Get());


	SmartDashboard::PutNumber("Shooter Actuator Motor", (double) RobotMap::shooterActuatorMotor.get()->Get());

	//Encoder
	SmartDashboard::PutNumber("Left encoder ticks", RobotMap::driveEncoderL->Get());
	//SmartDashboard::PutNumber("Left encoder 'distance'", RobotMap::drivetrainEncoder->GetDistance());
	SmartDashboard::PutNumber("Right encoder ticks", RobotMap::driveEncoderR->Get());
	//SmartDashboard::PutNumber("Right encoder 'distance'", RobotMap::drivetrainEncoder2->GetDistance());

	SmartDashboard::PutNumber("Average Distance", drivetrain->GetAverageEncoderDistance());
	SmartDashboard::PutNumber("Left Encoder Distance", drivetrain->GetEncoderDistance());
	SmartDashboard::PutNumber("Right Encoder Distance", drivetrain->GetEncoder2Distance());

	SmartDashboard::PutBoolean("Inverted Controls", inverted);

	SmartDashboard::PutNumber("Left Shifter", RobotMap::shifterL->Get());
	SmartDashboard::PutNumber("Right Shifter", RobotMap::shifterR->Get());

	SmartDashboard::PutNumber("Raw IR sensor voltage", RobotMap::shooterIR->GetVoltage());
	SmartDashboard::PutNumber("IR distance inches", ((27.86f * pow(RobotMap::shooterIR->GetVoltage(), -1.15f)) * 0.393701f));


	SmartDashboard::PutNumber("Rotation Speed", RobotMap::shooterRotateMotor->Get());

	SmartDashboard::PutNumber("NavX Pitch (in degrees)", RobotMap::NavX.get()->GetPitch());
	//printf("NavX Pitch (in degrees): %f\n", RobotMap::NavX.get()->GetPitch());
	SmartDashboard::PutNumber("NavX Roll (in degrees)", RobotMap::NavX.get()->GetRoll());
	//printf("NavX Roll (in degrees): %f\n", RobotMap::NavX.get()->GetRoll());
	SmartDashboard::PutNumber("NavX Yaw", (float) (RobotMap::NavX.get()->GetYaw()));
}

START_ROBOT_CLASS(Robot);
