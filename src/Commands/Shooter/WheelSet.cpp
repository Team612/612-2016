#include <Robot.h>
#include "WheelSet.h"

WheelSet::WheelSet(float speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterwheels.get());
	this->speed = speed;
	Robot::shooterwheels->setWheelSpeed(speed);
}

// Called just before this Command runs the first time
void WheelSet::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WheelSet::Execute()
{
	if ((fabs(Robot::shooterwheels->getLeftWheelSpeed() - this->speed)
			< this->THRESHHOLD)
			&& (fabs(Robot::shooterwheels->getRightWheelSpeed() - this->speed)
					< this->THRESHHOLD))
	{
		//this->isDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool WheelSet::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WheelSet::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WheelSet::Interrupted()
{

}
