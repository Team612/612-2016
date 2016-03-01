#include "ArmToPosition.h"

ArmToPosition::ArmToPosition(float position)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm.get());
	this->position = position;
}

// Called just before this Command runs the first time
void ArmToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmToPosition::Execute()
{
	Robot::arm.get()->SetArmPosition(position);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmToPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmToPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmToPosition::Interrupted()
{

}
