#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() :
		Subsystem("ShooterRotation")
{
	RotateMotor = RobotMap::shooterRotateMotor;
}

void ShooterRotation::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShooterJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

float ShooterRotation::GetSpeed()
{
	return RotateMotor->Get();
}

void ShooterRotation::SetSpeed(float speed)
{
	RotateMotor->Set(speed);
}

void ShooterRotation::ShooterHome()
{
	this->SetSpeed(this->HOME_POS);
	//TODO: Actually make this return to the home pos
}

void ShooterRotation::SetMode(CANTalon::ControlMode mode)
{
	RotateMotor->SetControlMode(mode);
}
