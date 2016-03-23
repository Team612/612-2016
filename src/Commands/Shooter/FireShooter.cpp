#include "FireShooter.h"

FireShooter::FireShooter(ShooterActuatorPosition pos)
{
    Requires(Robot::shooteractuator.get());
    this->position = pos;
}

// Called just before this Command runs the first time
void FireShooter::Initialize()
{
	Robot::shooteractuator->SetPosition(position);
	count = 0;
}

// Called repeatedly when this Command is scheduled to run
void FireShooter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FireShooter::IsFinished()
{
	if(position == ShooterActuatorPosition::Neutral)
		return true;
	/*
	if(Robot::shooterlever->AtSetPosition())
		count++;
	printf("Count: %d", count);
	return count >= 30;*/
	return false;
}

// Called once after isFinished returns true
void FireShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireShooter::Interrupted()
{
	//std::printf("Warning: FireShooter interrupted.\n");
}
