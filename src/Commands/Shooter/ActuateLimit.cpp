#include "ActuateLimit.h"
#include "Robot.h"
#include "RobotMap.h"

ActuateLimit::ActuateLimit()
{
	Requires(Robot::shooteractuator.get());
	/*failsafe = new Timer();
	start_time = 0;*/
}

void ActuateLimit::Initialize()
{
	//Robot::shooteractuator.get()->SetSpeed(-0.4f);
	/*failsafe->Start();
	start_time = failsafe->Get();
	std::printf("Info: ActuateLimit start time is: %f\n", start_time);*/
	finished = false;
}

void ActuateLimit::Execute()
{
	if((int)RobotMap::shooterActuatorLSwitch2.get()->Get() == 0)
	{
		RobotMap::shooterActuatorMotor.get()->Set(0.0f);
		finished = true;
	}
	else
	{
		printf("Info: moving backwards\n");
		RobotMap::shooterActuatorMotor.get()->Set(-0.4);
	}
}

bool ActuateLimit::IsFinished()
{
	return finished;
}

void ActuateLimit::End()
{
	//failsafe->Reset();
	//std::printf("Info: ActuateLimit end\n");
	Robot::shooteractuator.get()->SetSpeed(0.0f);
}

void ActuateLimit::Interrupted()
{
	//failsafe->Reset();
	//std::printf("Warning: ActuateLimit interrupted!\n");
	Robot::shooteractuator.get()->SetSpeed(0.0f);
}
