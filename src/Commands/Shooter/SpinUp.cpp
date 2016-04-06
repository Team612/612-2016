#include "SpinUp.h"
#include "Robot.h"

SpinUp::SpinUp()
{
	Requires(Robot::shooterwheels.get());
	SetTimeout(0.5);
}

void SpinUp::Initialize()
{
	Robot::shooterwheels.get()->StartManuel();
}

void SpinUp::Execute()
{
	Robot::shooterwheels.get()->ManuelSet(1.0f);
}

bool SpinUp::IsFinished()
{
	return IsTimedOut();
}

void SpinUp::End()
{

}

void SpinUp::Interrupted()
{

}
