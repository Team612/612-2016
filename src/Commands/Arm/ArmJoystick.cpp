#include "ArmJoystick.h"

ArmJoystick::ArmJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm.get());
}

// Called just before this Command runs the first time
void ArmJoystick::Initialize()
{
	Robot::arm->SetArmMode(CANSpeedController::kPercentVbus);
}

// Called repeatedly when this Command is scheduled to run
void ArmJoystick::Execute()
{

	dpadValue = Robot::oi->getDriver()->GetPOV(6);


	if (dpadValue == 0) {
		Robot::arm->SetArm(1);
	}
	else if (dpadValue == 4) {
		Robot::arm->SetArm(-1);
	}

	//Robot::arm->SetArm(Robot::oi->getDriver()->GetPOV(6));
}

// Make this return true when this Command no longer needs to run execute()
bool ArmJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmJoystick::Interrupted()
{

}
