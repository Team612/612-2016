#include "LowGear.h"
#include "Robot.h"
LowGear::LowGear()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void LowGear::Initialize()
{
	Robot::shifter->SetShifter(0.0f);
}

// Called repeatedly when this Command is scheduled to run
void LowGear::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LowGear::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LowGear::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowGear::Interrupted()
{

}
