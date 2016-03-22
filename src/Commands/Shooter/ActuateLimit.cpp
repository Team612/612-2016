#include "ActuateLimit.h"
#include "Robot.h"
#include "RobotMap.h"

ActuateLimit::ActuateLimit()
{
	Requires(Robot::shooteractuator.get());
	failsafe = new Timer();
	start_time = 0;
}

void ActuateLimit::Initialize()
{
	failsafe->Start();
	start_time = failsafe->Get();
	std::printf("Info: ActuateLimit start time is: %f\n", start_time);
}

void ActuateLimit::Execute()
{
	//std::printf("Info: Failsafe timer: %d\n", failsafe->Get());

	float current_time = failsafe->Get();
	std::printf("Info Current time: %f Elapsed time: %f\n", (double) current_time, (double) abs(start_time - current_time));

	if(RobotMap::shooterActuatorLSwitch.get()->Get())
		Robot::shooteractuator.get()->SetSpeed(0.1f);
	else if(!RobotMap::shooterActuatorLSwitch.get()->Get() || abs(start_time - current_time)  > 2)
	{
		if(abs(start_time - current_time)  > 2)
		{
			std::printf("Warning: Shooter Actuator Limit switch not pressed.\n");
			std::printf("Warning: Falling back to 2 second failsafe!\n");
			Robot::shooteractuator.get()->SetSpeed(0.0f);
			finished = true;
		}
		else
		{
			std::printf("Info: Shooter Actuator Limit switch pressed\n");
			Robot::shooteractuator.get()->SetSpeed(0.0f);
			finished = true;
		}
	}
}

bool ActuateLimit::IsFinished()
{
	return finished;
}

void ActuateLimit::End()
{
	//failsafe->Reset();
	Robot::shooteractuator.get()->SetSpeed(0.0f);
}

void ActuateLimit::Interrupted()
{
	//failsafe->Reset();
	std::printf("Warning: ActuateLimit interrupted!\n");
	Robot::shooteractuator.get()->SetSpeed(0.0f);
}
