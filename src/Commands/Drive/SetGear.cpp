#include "SetGear.h"

SetGear::SetGear(float gear)
{
	Requires(Robot::shifter.get());
	this->gear = gear;
}

void SetGear::Initialize()
{
	Robot::shifter->Set(gear);
}

void SetGear::Execute() { }

bool SetGear::IsFinished()
{
	return false;
}

void SetGear::End() { }

void SetGear::Interrupted() { }
