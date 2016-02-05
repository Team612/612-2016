#include "ArmMove.h"

ArmMove::ArmMove()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm.get());
	gj = Robot::oi->getGunner();
}

// Called just before this Command runs the first time
void ArmMove::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmMove::Execute()
{
	Robot::arm->moveArm(gj->GetY()); //The arm moves according to the value of the gunner's Y axis
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmMove::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMove::Interrupted()
{

}
