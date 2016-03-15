#include "Robot.h"

#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Shooter/FireShooter.h"
#include "Commands/Shooter/ShooterTest.h"
#include "Commands/Drive/DriveSet.h"
#include "Commands/Drive/DriveDistance.h"
#include "SmartDashboard/SmartDashboard.h"

#include "Commands/Autonomous/Sequences/SimpleAutonomous.h"
#include "Commands/Autonomous/Sequences/AlignAutonomous.h"

std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<ShooterWheels> Robot::shooterwheels;
std::shared_ptr<ShooterRotation> Robot::shooterrotation;
std::shared_ptr<ShooterLever> Robot::shooterlever;
std::shared_ptr<Shifter> Robot::shifter;
std::unique_ptr<OI> Robot::oi;
std::unique_ptr<Vision> Robot::vision;
std::shared_ptr<CameraServer> Robot::server;
bool Robot::inverted;

std::shared_ptr<SendableChooser> Robot::autoChooser;

void Robot::RobotInit()
{
	RobotMap::init();
	server.reset(CameraServer::GetInstance());
	drivetrain.reset(new Drivetrain());
	shooterwheels.reset(new ShooterWheels());
	shooterrotation.reset(new ShooterRotation());
	vision.reset(new Vision());
	shooterlever.reset(new ShooterLever());
	shifter.reset(new Shifter());

	/*
	 * This MUST be here. If the OI creates Commands (which it very likely
	 * will), constructing it during the construction of CommandBase (from
	 * which commands extend), subsystems are not guaranteed to be
	 * yet. Thus, their requires() statements may grab null pointers. Bad
	 * news. Don't move it.
	 */

	/*
	 * I'm not sure CommandBas exists any more...
	 */

	oi.reset(new OI());

	autoChooser.reset(new SendableChooser());
	InitSmartDashboard();

	SmartDashboard::PutNumber("P", 0.0);
	SmartDashboard::PutNumber("I", 0.0);
	SmartDashboard::PutNumber("D", 0.0);
	SmartDashboard::PutNumber("Angle", 0.0);
	SmartDashboard::PutData("Start Aligning", new ShooterTest());


	SmartDashboard::PutData("Autonomous Defense Chooser", autoChooser.get());

	// instantiate the command used for the autonomous period
	//autonomousCommand.reset((Command *) chooser->GetSelected());
	//drivejoystick.reset(new DriveJoystick());
	//armjoystick.reset(new ArmJoystick());
	//armmove.reset(new ArmMove());
	//autowheels.reset(new AutoWheels());

	server.get()->SetQuality(50);
	server.get()->StartAutomaticCapture("cam1");
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
	autonomousCommand.reset((Command *) autoChooser->GetSelected());

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	//drivejoystick->Start();
	//armmove->Start();
	//autowheels->Start();
	invertcontrols->Start();
}

void Robot::TeleopPeriodic()
{
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

	//Commands
	SmartDashboard::PutData("Stop Drivetrain", new DriveSet(0.0f, 0.0f));
	SmartDashboard::PutData("Drive Joystick", new DriveJoystick());
	SmartDashboard::PutData("Drive Distance", new DriveDistance(240));
	SmartDashboard::PutData("Shooter Test", new ShooterTest());

	//autonomous
	autoChooser->AddDefault("Low Bar (align)", new AlignAutonomous());
	autoChooser->AddObject("Other Defense (align)", new AlignAutonomous(5, 0.8f));
	autoChooser->AddObject("Low Bar", new SimpleAutonomous());
	autoChooser->AddObject("Other Defense", new SimpleAutonomous(5, 0.8f));

	SmartDashboard::PutData("Autonomous Defense Chooser", autoChooser.get());
}

void Robot::PeriodicSmartDashboard()
{
	SmartDashboard::PutNumber("Shooter Absolute Encoder", RobotMap::shooterEncoder.get()->GetVoltage());
	SmartDashboard::PutNumber("Arm Absolute Encoder", RobotMap::armRotationDetect.get()->GetVoltage());

	//Encoder
	SmartDashboard::PutNumber("Left encoder ticks", RobotMap::driveEncoderLeft->Get());
	//SmartDashboard::PutNumber("Left encoder 'distance'", RobotMap::drivetrainEncoder->GetDistance());
	SmartDashboard::PutNumber("Right encoder ticks", RobotMap::driveEncoderRight->Get());
	//SmartDashboard::PutNumber("Right encoder 'distance'", RobotMap::drivetrainEncoder2->GetDistance());

	SmartDashboard::PutNumber("Average Distance", drivetrain->GetAverageEncoderDistance());
	SmartDashboard::PutNumber("Left Encoder Distance", drivetrain->GetEncoderDistance());
	SmartDashboard::PutNumber("Right Encoder Distance", drivetrain->GetEncoder2Distance());

	SmartDashboard::PutBoolean("Inverted Controls", inverted);

	SmartDashboard::PutNumber("Servo 1", RobotMap::shifterLeft->Get());
	SmartDashboard::PutNumber("Servo 2", RobotMap::shifterRight->Get());

	SmartDashboard::PutNumber("Raw IR sensor voltage", RobotMap::shooterLeverDetect->GetVoltage());
	SmartDashboard::PutNumber("IR distance inches", ((27.86f * pow(RobotMap::shooterLeverDetect->GetVoltage(), -1.15f)) * 0.393701f));

	SmartDashboard::PutNumber("Rotation Speed", RobotMap::shooterRotateMotor->Get());
}

START_ROBOT_CLASS(Robot);
