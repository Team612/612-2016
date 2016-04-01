#include <Commands/Shooter/ShooterControl.h>
#include "Robot.h"

#include "CameraServer.h"

#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/DriveSet.h"
#include "Commands/Autonomous/Autonomous.h"
#include "Commands/Drive/DriveDistance.h"
#include <SmartDashboard/SmartDashboard.h>
#include "Commands/Shooter/ShooterTest.h"
#include "Commands/Arm/ArmJoystick.h"

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterWheels> Robot::shooterwheels;
std::shared_ptr<ShooterRotation> Robot::shooterrotation;
std::shared_ptr<ShooterActuator> Robot::shooteractuator;
std::shared_ptr<Shifter> Robot::shifter;
std::shared_ptr<Arm> Robot::arm;
std::unique_ptr<OI> Robot::oi;

bool Robot::inverted;
int Robot::robot_yaw;

/*
 * robot_yaw exists so we don't have to worry about calibrating the NavX
 * before every match. We just get the initial yaw and compare the current
 * yaw with the initial. We only need to know if we're off by whatever
 * amount.
 */


void Robot::RobotInit()
{
	RobotMap::init();

	arm.reset(new Arm());
	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	shooteractuator.reset(new ShooterActuator());
	shifter.reset(new Shifter());

	oi.reset(new OI());

	//server.reset(CameraServer::GetInstance());

	chooser.reset(new SendableChooser());



	InitSmartDashboard();

	//SmartDashboard::PutData("FireShooter", new FireShooter());
	//SmartDashboard::PutData("Autonomous", new Autonomous());

	// instantiate the command used for the autonomous period
	autonomousCommand.reset(new Autonomous(7.0f, 1.0f));
	drivejoystick.reset(new DriveJoystick());
	armJoystick.reset(new ArmJoystick());
	//armjoystick.reset(new ArmJoystick());
	//armmove.reset(new ArmMove());
	//autowheels.reset(new AutoWheels());

	//server.get()->SetQuality(50);
	//server.get()->StartAutomaticCapture("cam1");
	robot_yaw = RobotMap::NavX.get()->GetYaw();
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
	robot_yaw = RobotMap::NavX.get()->GetYaw();
	printf("Initial Autonomous Robot Yaw: %f\n", robot_yaw);
	//autonomousCommand.reset((Command *) chooser->GetSelected());

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
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
	armJoystick->Start();
	shifter->Set(Shifter::LOW);
	//shooterrotation->PIDEnable(true);
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
	shooterrotation->SmartDashboardOutput();
	//Commands
	SmartDashboard::PutData("Stop Drivetrain", new DriveSet(0.0f, 0.0f));
	SmartDashboard::PutData("Drive Joystick", new DriveJoystick());
	SmartDashboard::PutData("Drive Distance", new DriveDistance(240));
	SmartDashboard::PutData("Shooter Test", new ShooterTest());

	//autonomous
	/*chooser->AddDefault("Low Bar", new Autonomous(Defense::LOW_BAR));
	chooser->AddObject("Cheval de Frise", new Autonomous(Defense::CHEVAL_DE_FRISE));
	chooser->AddObject("Draw Bridge", new Autonomous(Defense::DRAW_BRIDGE));
	chooser->AddObject("Moat", new Autonomous(Defense::MOAT));
	chooser->AddObject("Portcullis", new Autonomous(Defense::PORTCULLIS));
	chooser->AddObject("Rock Wall", new Autonomous(Defense::ROCK_WALL));
	chooser->AddObject("Rough Terrain", new Autonomous(Defense::ROUGH_TERRAIN));
	chooser->AddObject("Sally Port", new Autonomous(Defense::SALLY_PORT));*/

	//SmartDashboard::PutData("Autonomous Defense Chooser", chooser.get());
}

void Robot::PeriodicSmartDashboard()
{
	SmartDashboard::PutNumber("Shooter Absolute Encoder", RobotMap::shooterAbsEncoder.get()->GetVoltage());

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
}

START_ROBOT_CLASS(Robot);
