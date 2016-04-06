#include "SetShooter.h"
#include "Robot.h"

SetShooter::SetShooter(float speed)
{
	Requires(Robot::shooterwheels.get());
	this->speed = speed;
}

void SetShooter::Initialize()
{
	Robot::shooterwheels.get()->StartManual();
}

void SetShooter::Execute()
{
	Robot::shooterwheels.get()->ManualSet(speed);
}

bool SetShooter::IsFinished()
{
	return false;
}

void SetShooter::End()
{

}

void SetShooter::Interrupted()
{
	Robot::shooterwheels.get()->ManualSet(0.0f);
}
