#include "StopShooter.h"
#include "Robot.h"

StopShooter::StopShooter()
{
	Requires(Robot::shooterwheels.get());
}

void StopShooter::Initialize()
{
	Robot::shooterwheels.get()->StartManual();
	Robot::shooterwheels.get()->ManualSet(0.0f);
}

void StopShooter::Execute()
{
}

bool StopShooter::IsFinished()
{
	return true;
}

void StopShooter::End()
{
	//Robot::shooterwheels.get()->ManualSet(0.0f);
}

void StopShooter::Interrupted()
{
	//Robot::shooterwheels.get()->ManualSet(0.0f);
	//std::printf("ERROR: StopShooter Interrupted!");
}
