#include "SpinUp.h"
#include "Robot.h"

SpinUp::SpinUp()
{
	Requires(Robot::shooterwheels.get());

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
	return false;
}

void SpinUp::End()
{

}

void SpinUp::Interrupted()
{
	Robot::shooterwheels.get()->ManuelSet(0.0f);
}
