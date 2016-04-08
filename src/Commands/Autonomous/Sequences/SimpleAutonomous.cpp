#include "SimpleAutonomous.h"

#include "Robot.h"
#include "RobotMap.h"

SimpleAutonomous::SimpleAutonomous(float time, float speed)
{
	Requires(Robot::drivetrain.get());

	this->time = time;
	this->speed = speed;
	original_speed = speed;
	//speed and original_speed start out the same
	autoTime = new Timer();
	start_time = 0.0;
}

void SimpleAutonomous::Initialize()
{
	autoTime->Start();
	start_time = autoTime->Get();
	Robot::drivetrain.get()->SetArcadeDrive(speed, 0);
}

void SimpleAutonomous::Execute()
{
	current_time = autoTime->Get();

	//First check, see if we're tilted
	if(!(abs(RobotMap::NavX.get()->GetPitch()) < THRESHOLD) ||
			!(abs(RobotMap::NavX.get()->GetRoll()) < THRESHOLD))
		/*
		 * if the pitch of the robot is not in the threshold OR
		 * if the roll of the robot is not in the threshold
		 */

	{
		std::printf("Info: Incrementing speed\n");
		//We're on a defense, increase speed slightly, this does run 60 times a second
		speed *= TIMES_INCREMENT;
	}

	//Second check, see if we're on course
	if(!(abs(RobotMap::NavX.get()->GetYaw()) < MAX_YAW_ERROR))
		//If we're off by over 10 degrees (Threshold)
	{
		if(RobotMap::NavX.get()->GetYaw() > 0)
		{
			/*
			 * if the yaw is too positive, meaning
			 * the robot is too clockwise
			 */

			rotation -= ADD_INCREMENT;

		}
		else if(RobotMap::NavX.get()->GetYaw() < 0)
		{
			/*
			 * if the yaw is too negative, meaning
			 * the robot is too counter clockwise
			 */
			rotation += ADD_INCREMENT;
		}
	}
	else
	//If inside the threshold
	{
		rotation = 0;
	}

	//Third check, if everything is normal
	if(abs(RobotMap::NavX.get()->GetYaw()) < MAX_YAW_ERROR &&
			abs(RobotMap::NavX.get()->GetPitch()) < THRESHOLD &&
			abs(RobotMap::NavX.get()->GetRoll()) < THRESHOLD)
		/*
		 * If the pitch, roll, and yaw are all in threshold, we're flat
		 * again. This means we've cleared the defense or are on a flat
		 * surface. No reason to be going so fast!
		 */
	{
		std::printf("Info: Speed reset\n");
		//set to original speed
		speed = original_speed;
		rotation = 0;
	}

	//Other debugging tools
	if(speed > 1)
		std::printf("Warning: Maxing out motors!\n");

	std::printf("Info: Motor Speed: %f, Rotation Speed: %f\n", speed, rotation);
	std::printf("Info: Yaw: %f\n", RobotMap::NavX.get()->GetYaw());
	Robot::drivetrain.get()->SetArcadeDrive(speed, rotation); //update robot speed
}

bool SimpleAutonomous::IsFinished()
{
	//std::printf("Autonomous timer: %f\n", (float) abs(current_time - start_time));
	SmartDashboard::PutNumber("Autonomous Timer", (float) abs(current_time - start_time));

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
	printf("Info: End auto driving.\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}

void SimpleAutonomous::Interrupted()
{
	printf("Warning: Autonomous driving interrupted\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}
