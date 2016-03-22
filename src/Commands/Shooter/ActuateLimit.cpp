#include "ActuateLimit.h"
#include "Robot.h"
#include "RobotMap.h"

ActuateLimit::ActuateLimit()
{
	Requires(Robot::shooteractuator.get());
}

void ActuateLimit::Initialize()
{

}

void ActuateLimit::Execute()
{
	if(RobotMap::shooterActuatorLSwitch.get()->Get())
		Robot::shooteractuator.get()->SetSpeed(0.1f);
	else if(!RobotMap::shooterActuatorLSwitch.get()->Get())
	{
		std::printf("Warning: Shooter Actuator Limit switch pressed\n");
		Robot::shooteractuator.get()->SetSpeed(0.0f);
		finished = true;
	}
}

bool ActuateLimit::IsFinished()
{
	return finished;
}

void ActuateLimit::End()
{
	//should never be called, but just in case
	Robot::shooteractuator.get()->SetSpeed(0.0f);
}

void ActuateLimit::Interrupted()
{
	std::printf("Warning: ActuateLimit interrupted!\n");
	Robot::shooteractuator.get()->SetSpeed(0.0f);
}
