#include "Shifter.h"
#include "../RobotMap.h"

Shifter::Shifter() :
		Subsystem("Shifter")
{
	shifterL = RobotMap::shifterL;
	shifterR = RobotMap::shifterR;
}

void Shifter::InitDefaultCommand() { }

void Shifter::Set(float shiftPower)
{
	shifterL->Set(shiftPower);
	shifterR->Set(shiftPower);
}
float Shifter::Get()
{
	 return (shifterL->Get() + shifterR->Get()) / 2;
}
