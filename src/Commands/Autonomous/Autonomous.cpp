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
	Robot::drivetrain.get()->SetTankDrive(speedL, speedR);
}

void Autonomous::Execute()
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
		speedL *= INCREMENT;
		speedR *= INCREMENT;
	}

	//Second check, see if we're on course
	if(!abs(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw()) < MAX_YAW_ERROR)
		//If we're off by over 10 degrees
	{
		if(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw() > 0)
		{
			/*
			 * if the difference is positive, meaning
			 * the robot is too clockwise
			 */
			//TODO: Make sure this rotates the right way

			speedL /= INCREMENT;
			speedR *= INCREMENT;

		}
		else if(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw() < 0)
		{
			/*
			 * if the difference is negative, meaning
			 * the robot is too counter clockwise
			 */
			speedL *= INCREMENT;
			speedR /= INCREMENT;
		}
	}
	else if(abs(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw()) < MAX_YAW_ERROR)
	//If inside the threshold
	{
		//make these two the same so we stop turning but maintain speed
		if(speedL > speedR)
			speedR = speedL;
		else if(speedR > speedL)
			speedL = speedR;
	}

	//Third check, if everything is normal
	if(abs(Robot::robot_yaw - RobotMap::NavX.get()->GetYaw()) < MAX_YAW_ERROR &&
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
		speedL = original_speed;
		speedR = original_speed;
	}

	//Other debugging tools
	if(speedL > 1)
		std::printf("Warning: Maxing out left motors!\n");
	else if(speedR > 1)
		std::printf("Warning: Maxing out right motors!\n");

	std::printf("Info: Left Motor Speed: %f, Right Motor Speed: %f\n", speedL, speedR);
	Robot::drivetrain.get()->SetTankDrive(speedL, speedR); //update robot speed
}

bool Autonomous::IsFinished()
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
