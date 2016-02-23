#include "ArmMove.h"

ArmMove::ArmMove()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void ArmMove::Initialize()
{

	driverJoystick = Robot::oi->getDriver();

}
// Called repeatedly when this Command is scheduled to run
void ArmMove::Execute()
{
	if(Robot::oi->getDriver()->GetPOV() == 0 || Robot::oi->getDriver()->GetPOV() == 7 || Robot::oi->getDriver()->GetPOV() == 1)
		Robot::arm->Set(0.8f);
	else if(Robot::oi->getDriver()->GetPOV() == 5 || Robot::oi->getDriver()->GetPOV() == 4 || Robot::oi->getDriver()->GetPOV() == 3)
		Robot::arm->Set(-0.8f);
	else if(Robot::oi->getDriver()->GetPOV() == -01)
		Robot::arm->Set(0.0f);
	else
		Robot::arm->Set(0.0f);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmMove::End()
{
	Robot::arm->Set(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMove::Interrupted()
{
	Robot::arm->Set(0.0f);
}
