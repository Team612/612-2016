#include "ActuateLimit.h"
#include "Robot.h"
#include "RobotMap.h"

ActuateLimit::ActuateLimit()
{
	Requires(Robot::shooteractuator.get());
	//failsafe = new Timer();
	start_time = std::chrono::high_resolution_clock::now();
}

void ActuateLimit::Initialize()
{
	//failsafe->Start();
}

void ActuateLimit::Execute()
{
	//std::printf("Info: Failsafe timer: %d\n", failsafe->Get());
	auto current_time = std::chrono::high_resolution_clock::now();
	std::printf("Info: Failsafe timer: %f", (double)(current_time - start_time).count());

	if(RobotMap::shooterActuatorLSwitch.get()->Get())
		Robot::shooteractuator.get()->SetSpeed(0.1f);
	else if(!RobotMap::shooterActuatorLSwitch.get()->Get() || /*failsafe->HasPeriodPassed(2)*/ (double)(current_time - start_time).count() == 2)
	{
		if((double)(current_time - start_time).count() == 2)
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
