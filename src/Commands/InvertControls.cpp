#include "InvertControls.h"

InvertControls::InvertControls()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void InvertControls::Initialize()
{
	driverJoy.reset();
	driverJoy = Robot::oi->getDriver();
}

// Called repeatedly when this Command is scheduled to run
void InvertControls::Execute()
{
	if(driverJoy->GetRawAxis(3) > 0.5)
	{
		Robot::drivetrain->SetInversion(true);
	}else if(driverJoy->GetRawAxis(3) < 0.5)
	{
		Robot::drivetrain->SetInversion(false);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool InvertControls::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void InvertControls::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InvertControls::Interrupted()
{

}
