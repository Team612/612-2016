#include "ShooterJoystick.h"
#include <CANSpeedController.h>
#include "OI.h"
ShooterJoystick::ShooterJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterrotation.get());
}

// Called just before this Command runs the first time
void ShooterJoystick::Initialize()
{
	Robot::shooterrotation->SetShooterMode(CANSpeedController::kPercentVbus);
}

// Called repeatedly when this Command is scheduled to run
void ShooterJoystick::Execute()
{
	Robot::shooterrotation->SetShooter(Robot::oi->getGunner()->GetRawAxis(4));
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterJoystick::Interrupted()
{

}
