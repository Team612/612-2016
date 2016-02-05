#include "ServoPush.h"

ServoPush::ServoPush()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterlever.get());
}

// Called just before this Command runs the first time
void ServoPush::Initialize()
{
	Robot::shooterlever.get()
}

// Called repeatedly when this Command is scheduled to run
void ServoPush::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ServoPush::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ServoPush::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoPush::Interrupted()
{

}
