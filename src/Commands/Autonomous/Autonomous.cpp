#include "Autonomous.h"
#include "AutoBreach.h"

Autonomous::Autonomous(float time, float speed)
{
	Requires(Robot::drivetrain.get());

	this->time = time;
	this->speed = speed;
	autoTime = new Timer();
	start_time = 0.0;
	current_time = 0.0;
}

void Autonomous::Initialize()
{
	autoTime->Start();
	start_time = autoTime->Get();
}

void Autonomous::Execute()
{
	current_time = autoTime->Get();
	Robot::drivetrain.get()->SetTankDrive(speed, speed);
}

bool Autonomous::IsFinished()
{
	std::printf("Autonomous timer: %f\n", (float) abs(current_time - start_time));

	if(abs(current_time - start_time) >= time)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Autonomous::End()
{
	printf("Info: End auto\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}

void Autonomous::Interrupted()
{
	printf("Warning: Autonomous interrupted\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}
