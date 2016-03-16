#include <Commands/Shooter/ShooterControl.h>
#include "Robot.h"

#include "CameraServer.h"

#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/DriveSet.h"
#include "Commands/Autonomous/Autonomous.h"
#include "Commands/Drive/DriveDistance.h"
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Shooter/ShooterTest.h"

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterWheels> Robot::shooterwheels;
std::shared_ptr<ShooterRotation> Robot::shooterrotation;
std::shared_ptr<ShooterActuator> Robot::shooteractuator;
std::shared_ptr<Shifter> Robot::shifter;
std::unique_ptr<OI> Robot::oi;

bool Robot::inverted;


void Robot::RobotInit()
{
	RobotMap::init();

	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	shooteractuator.reset(new ShooterActuator());
	shifter.reset(new Shifter());

	oi.reset(new OI());

	chooser.reset(new SendableChooser());

	InitSmartDashboard();

	//SmartDashboard::PutData("FireShooter", new FireShooter());
	//SmartDashboard::PutData("Autonomous", new Autonomous());

	// instantiate the command used for the autonomous period
	//autonomousCommand.reset((Command *) chooser->GetSelected());
	drivejoystick.reset(new DriveJoystick());
	//armjoystick.reset(new ArmJoystick());
	//armmove.reset(new ArmMove());
	//autowheels.reset(new AutoWheels());

	server->SetQuality(50);
	server->StartAutomaticCapture("cam1");
}

void Robot::DisabledInit()
{

}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit()
{
	shifter->Set(Shifter::LOW);
	//autonomousCommand.reset((Command *) chooser->GetSelected());
//
	//if (autonomousCommand.get() != nullptr)
		//autonomousCommand->Start();

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
	PeriodicSmartDashboard();
}

void Robot::TeleopInit()
{
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
		
	drivejoystick->Start();
	shifter->Set(Shifter::LOW);
}

void Robot::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();

	PeriodicSmartDashboard();
}

void Robot::TestPeriodic()
{
	lw->Run();
}

void Robot::InitSmartDashboard()
{
	//ShooterPID
	// TODO: Actually replace with intelligent usage of PutData
	SmartDashboard::PutNumber("P", 0.0);
	SmartDashboard::PutNumber("I", 0.0);
	SmartDashboard::PutNumber("D", 0.0);
	SmartDashboard::PutNumber("Angle", 0.0);

	//Commands
	SmartDashboard::PutData("Stop Drivetrain", new DriveSet(0.0f, 0.0f));
	SmartDashboard::PutData("Drive Joystick", new DriveJoystick());
	SmartDashboard::PutData("Drive Distance", new DriveDistance(240));
	SmartDashboard::PutData("Shooter Test", new ShooterTest());

	//autonomous
	chooser->AddDefault("Low Bar", new Autonomous(Defense::LOW_BAR));
	chooser->AddObject("Cheval de Frise", new Autonomous(Defense::CHEVAL_DE_FRISE));
	chooser->AddObject("Draw Bridge", new Autonomous(Defense::DRAW_BRIDGE));
	chooser->AddObject("Moat", new Autonomous(Defense::MOAT));
	chooser->AddObject("Portcullis", new Autonomous(Defense::PORTCULLIS));
	chooser->AddObject("Rock Wall", new Autonomous(Defense::ROCK_WALL));
	chooser->AddObject("Rough Terrain", new Autonomous(Defense::ROUGH_TERRAIN));
	chooser->AddObject("Sally Port", new Autonomous(Defense::SALLY_PORT));

	SmartDashboard::PutData("Autonomous Defense Chooser", chooser.get());
}

void Robot::PeriodicSmartDashboard()
{
	SmartDashboard::PutNumber("Shooter Absolute Encoder", RobotMap::shooterAbsEncoder.get()->GetVoltage());

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
}

START_ROBOT_CLASS(Robot);
