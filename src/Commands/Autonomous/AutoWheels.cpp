#include "AutoWheels.h"
#include "Robot.h"

AutoWheels::AutoWheels()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterwheels.get());
}

// Called just before this Command runs the first time
void AutoWheels::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoWheels::Execute()
{
	if(Robot::oi->getGunner()->GetRawAxis(3) > TOLERANCE) //Left trigger pressed down
		Robot::shooterwheels->setWheelSpeed(1.0f);
	else if(Robot::oi->getGunner()->GetRawAxis(2) > TOLERANCE) //Right trigger pressed down
		Robot::shooterwheels->setWheelSpeed(-0.75f);
	else if(Robot::oi->getGunner()->GetRawAxis(2) < TOLERANCE && Robot::oi->getGunner()->GetRawAxis(3) < TOLERANCE) //both released
		Robot::shooterwheels->setWheelSpeed(0.0f);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoWheels::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoWheels::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoWheels::Interrupted()
{

}
