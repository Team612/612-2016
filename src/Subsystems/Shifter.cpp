#include "Shifter.h"
#include "../RobotMap.h"
#include <Commands/Drive/SetGear.h>

Shifter::Shifter() :
		Subsystem("Shifter")
{
	shifterL = RobotMap::shifterL;
	shifterR = RobotMap::shifterR;
}

void Shifter::InitDefaultCommand()
{
	SetDefaultCommand(new SetGear(LOW));
}
void Shifter::Set(float shiftPower)
{
	shifterL->Set(shiftPower);
	shifterR->Set(shiftPower);
}
float Shifter::Get()
{
	 return (shifterL->Get() + shifterR->Get()) / 2;
}
