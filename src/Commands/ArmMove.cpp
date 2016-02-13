#include "ArmMove.h"

ArmMove::ArmMove()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::arm.get());

	isXbox = true;
	myVal = 0.0f;
}

// Called just before this Command runs the first time
void ArmMove::Initialize()
{

	driverJoystick = Robot::oi->getDriver();

}
// Called repeatedly when this Command is scheduled to run
void ArmMove::Execute()
{
	if (isXbox)
	{
		myVal = -(Robot::oi->getGunner()->GetRawAxis(myAxis));
	}
	else
	{
		myVal = Robot::oi->getGunner()->GetY();
	}

	if (myVal > DEADZONE)
	{
		myVal = (myVal - DEADZONE) * ((float)1 / ((float)1 - DEADZONE));
	}
	else if (myVal < -DEADZONE)
	{
		myVal = (myVal + DEADZONE) * ((float)1 / ((float)1 - DEADZONE));
	}
	else myVal = 0.0f;

	Robot::arm->moveArm(myVal);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmMove::End()
{
	Robot::arm->moveArm(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMove::Interrupted()
{
	Robot::arm->moveArm(0.0f);
}
