#include <Commands/Shooter/ShooterControl.h>
#include "Robot.h"

#include "CameraServer.h"

#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/DriveSet.h"
#include "Commands/Autonomous/Autonomous.h"
#include "Commands/Autonomous/Sequences/FindTarget.h"
#include "Commands/Autonomous/Sequences/AutoAlign.h"
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
std::shared_ptr<Vision> Robot::vision;
std::shared_ptr<SendableChooser> Robot::autoChooser;

bool Robot::inverted;


void Robot::RobotInit()
{
	RobotMap::init();

	arm.reset(new Arm());
	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	shooteractuator.reset(new ShooterActuator());
	shifter.reset(new Shifter());
	vision.reset(new Vision());

	oi.reset(new OI());

	//server.reset(CameraServer::GetInstance());

	chooser.reset(new SendableChooser());



	InitSmartDashboard();

	//SmartDashboard::PutData("FireShooter", new FireShooter());
	//SmartDashboard::PutData("Autonomous", new Autonomous());

	// instantiate the command used for the autonomous period
	//autonomousCommand.reset(new Autonomous(7.0f, 1.0f));
	drivejoystick.reset(new DriveJoystick());
	armJoystick.reset(new ArmJoystick());
	align.reset(new AutoAlign(FindTarget::LEFT));
	//armjoystick.reset(new ArmJoystick());
	//armmove.reset(new ArmMove());
	//autowheels.reset(new AutoWheels());
}

/*
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
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
	align->Start();
//	autonomousCommand.reset((Command *) autoChooser->GetSelected());
//	std::printf("Info: Set Auto command!\n");
//
//	if (autonomousCommand.get() != nullptr)
//		autonomousCommand->Start();


}

void Robot::AutonomousPeriodic()
{
	vision->PullValues(); //Keep this above the scheduler
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
	vision->PullValues(); //Keep this above the scheduler
	Scheduler::GetInstance()->Run();

#ifdef SHOOTERBACKUP
    auto gunner = -Robot::oi->getGunner()->GetRawAxis(1);
    if(gunner > TOLERANCE)
    {
    	printf("Fire\n");
        ;
    }
    else if (gunner < -TOLERANCE)
    {
    	printf("Intake\n");
        Intake();
    }
    else
    {
    	//printf("Stop\n");p
        Stop();
    }
	#endif
    PeriodicSmartDashboard();
}

void Robot::TestInit()
{

}

void Robot::TestPeriodic()
{
	lw->Run();
}

void Robot::InitSmartDashboard()
{
	//ShooterPID
	SmartDashboard::PutNumber("P", 0.0);
	SmartDashboard::PutNumber("I", 0.0);
	SmartDashboard::PutNumber("D", 0.0);
	SmartDashboard::PutNumber("Angle", 0.0);

	//Commands for debugging
	shooterrotation->SmartDashboardOutput();
	SmartDashboard::PutData("Stop Drivetrain", new DriveSet(0.0f, 0.0f));
	SmartDashboard::PutData("Drive Joystick", new DriveJoystick());
	SmartDashboard::PutData("Drive Distance", new DriveDistance(240));
	SmartDashboard::PutData("Shooter Test", new ShooterTest());
	//Auto Align
		SmartDashboard::PutData("Auto Right", new AutoAlign(FindTarget::Direction::RIGHT));
		SmartDashboard::PutData("Auto Left", new AutoAlign(FindTarget::Direction::LEFT));

	//autonomous
	autoChooser->AddObject("Low Bar", new SimpleAutonomous(6, 0.8f));
	autoChooser->AddObject("Other Defense", new SimpleAutonomous(7, 0.9f));

	SmartDashboard::PutData("Autonomous Defense Chooser", autoChooser.get());

}

void Robot::PeriodicSmartDashboard()
{

	SmartDashboard::PutNumber("Shooter Absolute Encoder", RobotMap::shooterAbsEncoder.get()->GetVoltage());

	//SmartDashboard::PutBoolean("Shooter Actuator Limit Switch", RobotMap::shooterActuatorLSwitch.get()->Get());
	//SmartDashboard::PutBoolean("Second Shooter Actuator Limit Switch", RobotMap::shooterActuatorLSwitch2.get()->Get());
	std::printf("Shooter Actuator Limit Switch: %i\n", (int) RobotMap::shooterActuatorLSwitch.get()->Get());
	std::printf("Second Shooter Actuator Limit Switch: %i\n", (int) RobotMap::shooterActuatorLSwitch.get()->Get());


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
}

START_ROBOT_CLASS(Robot);
