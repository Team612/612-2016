#include "ServoNeutral.h"

ServoNeutral::ServoNeutral()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	temp = ShooterLever::LeverServo1;
}

// Called just before this Command runs the first time
void ServoNeutral::Initialize()
{
	temp->Set(0.5f);
}

// Called repeatedly when this Command is scheduled to run
void ServoNeutral::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ServoNeutral::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ServoNeutral::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoNeutral::Interrupted()
{

}
