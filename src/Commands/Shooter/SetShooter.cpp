#include "SetShooter.h"
#include "Robot.h"

SetShooter::SetShooter(float speed, float timeout)
{
	Requires(Robot::shooterwheels.get());
	this->speed = speed;

	if(timeout != 0)
		SetTimeout(timeout);
}

void SetShooter::Initialize()
{
	Robot::shooterwheels->StartManual();
}

void SetShooter::Execute()
{
	Robot::shooterwheels->ManualSet(speed);
}

bool SetShooter::IsFinished()
{
	if(IsTimedOut())
		return true;
	else
		return false;
}

void SetShooter::End()
{
	Robot::shooterwheels->ManualSet(0.0f);
}

void SetShooter::Interrupted()
{
	Robot::shooterwheels->ManualSet(0.0f);
}
