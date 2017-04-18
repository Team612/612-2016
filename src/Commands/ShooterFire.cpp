#include "ShooterFire.h"
#include "Robot.h"
ShooterFire::ShooterFire()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterFire::Initialize()
{
 // this is where you set the angl for the shooter thing
	Robot::shooterwheels->setWheelSpeed(1.0);
}

// Called repeatedly when this Command is scheduled to run
void ShooterFire::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterFire::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterFire::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterFire::Interrupted()
{

}
