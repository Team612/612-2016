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
	Robot::shooterrotation->SetMode(CANSpeedController::kPercentVbus);
}

// Called repeatedly when this Command is scheduled to run
void ShooterJoystick::Execute()
{
	auto gunner = Robot::oi->getGunner()->GetRawAxis(5);
	if(gunner < TOLERANCE && gunner > -TOLERANCE)
		gunner = 0;
	Robot::shooterrotation->SetSpeed(gunner);
	printf("Gunner: %f \n", gunner);
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShooterJoystick::End()
{
	Robot::shooterrotation->SetSpeed(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterJoystick::Interrupted()
{
	Robot::shooterrotation->SetSpeed(0.0f);
}
