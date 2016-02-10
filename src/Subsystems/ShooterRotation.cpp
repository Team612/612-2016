#include "ShooterRotation.h"
#include "../RobotMap.h"

ShooterRotation::ShooterRotation() :
		Subsystem("ShooterRotation")
{
	RotateMotor = RobotMap::shooterRotateMotor
}

void ShooterRotation::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

float ShooterRotation::GetShooter() {
	return RotateMotor->Get();
}

void ShooterRotation::SetShooter(float position) {
	RotateMotor->Set(position);
}

void ShooterRotation::SetShooterMode(ControlMode mode) {
	RotateMotor->SetControlMode(mode);
}
