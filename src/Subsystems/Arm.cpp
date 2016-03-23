#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/Arm/ArmJoystick.h"

Arm::Arm() :
		Subsystem("Arm")
{
	rotateMotor = RobotMap::armRotateMotor;
}

void Arm::InitDefaultCommand()
{
	SetDefaultCommand(new ArmJoystick());
}

void Arm::SetSpeed(float speed)
{
	rotateMotor.get()->Set(speed);
}
