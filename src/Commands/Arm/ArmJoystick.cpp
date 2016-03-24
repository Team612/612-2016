#include "ArmJoystick.h"
#include "Robot.h"
#include "RobotMap.h"

ArmJoystick::ArmJoystick()
{
	Requires(Robot::arm.get());
}

void ArmJoystick::Initialize()
{

}

void ArmJoystick::Execute()
{
	if(Robot::oi.get()->getDriver()->GetRawAxis(2) > THRESHOLD) //left trigger
	{
		//goin' up?
		Robot::arm.get()->SetSpeed(Robot::oi.get()->getDriver()->GetRawAxis(2));
	}
	else if(Robot::oi.get()->getDriver()->GetRawAxis(3) > THRESHOLD) //right trigger
	{
		//GERONIMO!!!!!!
		Robot::arm.get()->SetSpeed(-Robot::oi.get()->getDriver()->GetRawAxis(3));
	}
	else
	{
		Robot::arm.get()->SetSpeed(0.0f);
	}
}

bool ArmJoystick::IsFinished()
{
	return false;
}

void ArmJoystick::End()
{

}

void ArmJoystick::Interrupted()
{
	Robot::arm.get()->SetSpeed(0.0f);
	std::printf("Warning: ArmJoystick interrupted!\n");
}
