#include "AutoServo.h"

AutoServo::AutoServo()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterlever.get());
}

// Called just before this Command runs the first time
void AutoServo::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoServo::Execute()
{
	if( (Robot::shooterlever.get()->getIRInInches(Robot::shooterlever.get()->getBallDetector())) > (5.0f)) //nothing is seen for at least 5 inches
	{
		Robot::shooterlever.get()->SetServoAngle(0.5f);
	}
	else if((Robot::shooterlever.get()->getIRInInches(Robot::shooterlever.get()->getBallDetector())) < (1.0f)) //Does the IR see something within 1 inch
	{
		Robot::shooterlever.get()->SetServoAngle(0.0f); //set servo to clamp position
	}
	else //error prevention
	{
		Robot::shooterlever.get()->SetServoAngle(0.5f);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoServo::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoServo::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoServo::Interrupted()
{

}
