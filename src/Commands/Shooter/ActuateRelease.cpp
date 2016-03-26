#include "ActuateRelease.h"
#include "RobotMap.h"

ActuateRelease::ActuateRelease()
{

}

void ActuateRelease::Initialize()
{

}

void ActuateRelease::Execute()
{
	RobotMap::shooterActuatorMotor.get()->Set(-0.3f);
}

bool ActuateRelease::IsFinished()
{

	return (!RobotMap::shooterActuatorLSwitch.get()->Get());
}

void ActuateRelease::End()
{
	printf("Info: ActuatorRelease end\n");
	RobotMap::shooterActuatorMotor.get()->Set(0.0f);
}

void ActuateRelease::Interrupted()
{
	RobotMap::shooterActuatorMotor.get()->Set(0.0f);
}
