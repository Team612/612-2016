#include "ShooterJoystick.h"
#include <CANSpeedController.h>
#include "OI.h"

ShooterJoystick::ShooterJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterrotation.get());
}

// Called just before this Command runs the first time
void ShooterJoystick::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ShooterJoystick::Execute()
{
	auto joy = Robot::oi->getGunner();
	bool a = joy->GetRawButton(1), b = joy->GetRawButton(2),
			x = joy->GetRawButton(3), y = joy->GetRawButton(4);
	bool buttonPushed = a | b | x | y;

	std::printf("Button? " + buttonPushed);
	std::printf("A? " + a);
	std::printf("B? " + b);
	if(!buttonPushed)
	{
		if(Robot::shooterrotation->PIDEnabled())
			Robot::shooterrotation->PIDEnable(false);

		auto gunner = joy->GetRawAxis(5);
		if(gunner < TOLERANCE && gunner > -TOLERANCE)
			gunner = 0;

		Robot::shooterrotation->Gun(gunner);
	}
	else
	{
		if(!Robot::shooterrotation->PIDEnabled())
			Robot::shooterrotation->PIDEnable(true);
		if(x) Robot::shooterrotation->HomePos();
		if(b) Robot::shooterrotation->IntakePos();
		if(y) Robot::shooterrotation->ShootPos(90.0f);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterJoystick::End()
{
	Robot::shooterrotation->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterJoystick::Interrupted()
{
	Robot::shooterrotation->Stop();
}
