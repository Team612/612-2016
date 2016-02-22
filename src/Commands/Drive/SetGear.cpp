#include "SetGear.h"

SetGear::SetGear(float gear)
{
	Requires(Robot::shifter.get());
	this->gear = gear;
}

// Called just before this Command runs the first time
void SetGear::Initialize()
{
	Robot::shifter->Set(gear);
}

// Called repeatedly when this Command is scheduled to run
void SetGear::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetGear::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetGear::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetGear::Interrupted()
{

}
