#include "StopShooter.h"
#include "Robot.h"

StopShooter::StopShooter()
{
	Requires(Robot::shooterwheels.get());
}

void StopShooter::Initialize()
{
	Robot::shooterwheels.get()->StartManuel();
}

void StopShooter::Execute()
{
	Robot::shooterwheels.get()->ManuelSet(0.0f);
}

bool StopShooter::IsFinished()
{
	return true;
}

void StopShooter::End()
{
	Robot::shooterwheels.get()->ManuelSet(0.0f);
}

void StopShooter::Interrupted()
{
	Robot::shooterwheels.get()->ManuelSet(0.0f);
	std::printf("ERROR: StopShooter Interrupted!");
}
