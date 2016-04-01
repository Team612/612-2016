#include "Autonomous.h"
#include "AutoBreach.h"

#include "Robot.h"
#include "RobotMap.h"

Autonomous::Autonomous(float time, float speed)
{
	Requires(Robot::drivetrain.get());

	this->time = time;
	speedL = speed;
	speedR = speed;
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

	if(!(abs(RobotMap::NavX.get()->GetPitch()) < THRESHOLD) ||
			!(abs(RobotMap::NavX.get()->GetRoll()) < THRESHOLD))
		/*
		 * if the pitch of the robot is not in the threshold OR
		 * if the roll of the robot is not in the threshold
		 */

	{
		std::printf("Info: Incrementing speed\n");
		//increase speed slightly, this does run 60 times a second
		speedL = speedL + 0.001;
		speedR = speedR + 0.001;
	}
	else
		/*
		 * If the pitch and roll are both in threshold
		 */
	{
		std::printf("Info: Speed reset\n");
		//set to original speed
		speedL = original_speed;
		speedR = original_speed;
	}

	if(abs(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw()) < MAX_YAW_ERROR)
		//If we're off by over 10 degrees
	{
		if(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw() > 0)
		{
			//if the difference is positive
			/*
			 * TODO: Make sure
			 */

		}
	}

	Robot::drivetrain.get()->SetTankDrive(speedL, speedR); //update robot speed
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
