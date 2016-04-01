#include "Autonomous.h"
#include "AutoBreach.h"

Autonomous::Autonomous(float time, float speed)
{
	Requires(Robot::drivetrain.get());

	this->time = time;
	this->speed = speed;
	original_speed = speed;
	//speed and original_speed start out the same
	autoTime = new Timer();
	start_time = 0.0;
	current_time = 0.0;
}

void Autonomous::Initialize()
{
	autoTime->Start();
	start_time = autoTime->Get();
	Robot::drivetrain.get()->SetTankDrive(speed, speed);
}

void Autonomous::Execute()
{
	current_time = autoTime->Get();

	if(!(RobotMap::NavX.get()->GetPitch() > -THRESHOLD && RobotMap::NavX.get()->GetPitch() < THRESHOLD) ||
			!(RobotMap::NavX.get()->GetRoll() > -THRESHOLD && RobotMap::NavX.get()->GetRoll() < THRESHOLD))
		/*
		 * if the pitch of the robot is not in the threshold OR
		 * if the roll of the robot is not in the threshold
		 */

	{
		std::printf("Info: Incrementing speed\n");
		speed = speed + 0.05; //increase speed slightly
	}
	else
		/*
		 * If the pitch and roll are both in threshold
		 */
	{
		std::printf("Info: Speed reset\n");
		speed = original_speed; //set to original speed
	}

	Robot::drivetrain.get()->SetTankDrive(speed, speed); //update robot speed
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
