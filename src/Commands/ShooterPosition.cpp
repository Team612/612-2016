#include "ShooterPosition.h"

ShooterPosition::ShooterPosition(float shootpos)
{
	float shooterthing;
	shooterthing = shootpos;
	Requires(Robot::shooterrotation.get());

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ShooterPosition::Initialize()
{
	Robot::shooterrotation->SetShooterMode(CANTalon::kPosition);
	Robot::shooterrotation->SetShooter(shooterthing);
}

// Called repeatedly when this Command is scheduled to run
void ShooterPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShooterPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterPosition::Interrupted()
{

}
