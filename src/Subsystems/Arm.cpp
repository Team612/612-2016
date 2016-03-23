#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/Arm/ArmJoystick.h"

Arm::Arm() :
		Subsystem("Arm")
{

}

void Arm::InitDefaultCommand()
{
	//SetDefaultCommand(new ArmJoystick());
}

void Arm::SetSpeed(float speed)
{
	RobotMap::armRotateMotor.get()->Set(speed);
}
