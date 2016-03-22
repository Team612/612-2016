#include "ActuateLimit.h"
#include "Robot.h"
#include "RobotMap.h"

ActuateLimit::ActuateLimit()
{
	Requires(Robot::shooteractuator.get());
	failsafe = new Timer();
}

void ActuateLimit::Initialize()
{
	failsafe->Start();
}

void ActuateLimit::Execute()
{
	if(RobotMap::shooterActuatorLSwitch.get()->Get())
		Robot::shooteractuator.get()->SetSpeed(0.1f);
	else if(!RobotMap::shooterActuatorLSwitch.get()->Get())
	{
		std::printf("Info: Shooter Actuator Limit switch pressed\n");
		Robot::shooteractuator.get()->SetSpeed(0.0f);
		finished = true;
	}

	if(failsafe->Get() > 2)
	{
		std::printf("Warning: Shooter Actuator Limit switch not pressed.\n");
		std::printf("Warning: Falling back to 2 second failsafe!");
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
