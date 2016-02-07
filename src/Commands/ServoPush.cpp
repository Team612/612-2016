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
	/* TODO: The following code does not execute any action
	 */
	Robot::shooterlever.get()->SetServoPosition(0.5f); //I doubt this is right.
}

// Called repeatedly when this Command is scheduled to run
void ServoPush::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ServoPush::IsFinished()
{
	return true;
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
