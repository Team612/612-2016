#include "ActuateRelease.h"
#include "RobotMap.h"
#include "Robot.h"

ActuateRelease::ActuateRelease()
{
	Requires(Robot::shooteractuator.get());
}

void ActuateRelease::Initialize()
{

}

void ActuateRelease::Execute()
{
	RobotMap::shooterActuatorMotor.get()->Set(1.0f);
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
