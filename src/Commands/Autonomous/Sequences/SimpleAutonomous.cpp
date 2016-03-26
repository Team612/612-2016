#include "SimpleAutonomous.h"

SimpleAutonomous::SimpleAutonomous(float time, float speed)
{
	Requires(Robot::drivetrain.get());

	this->time = time;
	this->speed = speed;
	autoTime = new Timer();
	start_time = 0.0;
	current_time = 0.0;
}

void SimpleAutonomous::Initialize()
{
	autoTime->Start();
	start_time = autoTime->Get();
}

void SimpleAutonomous::Execute()
{
	current_time = autoTime->Get();
	Robot::drivetrain.get()->SetTankDrive(speed, speed);
}

bool SimpleAutonomous::IsFinished()
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

void SimpleAutonomous::End()
{
	printf("Info: End auto\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}

void SimpleAutonomous::Interrupted()
{
	printf("Warning: Autonomous interrupted\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}
