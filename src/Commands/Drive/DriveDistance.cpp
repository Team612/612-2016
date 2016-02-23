#include "DriveDistance.h"
#include "Robot.h"

DriveDistance::DriveDistance(float end_distance) : PIDCommand("DriveDistance", 1.0, 0.0, 0.0) //default values
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain.get());
	this->end_distance = end_distance;

	GetPIDController()->SetContinuous(true); //I think...


}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	GetPIDController()->SetSetpoint(end_distance);
}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveDistance::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{

}
