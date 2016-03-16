#include "Shifter.h"
#include "../RobotMap.h"

Shifter::Shifter() :
		Subsystem("Shifter")
{
	shifterL = RobotMap::shifterL;
	shifterR = RobotMap::shifterR;
}

void Shifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
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
// Put methods for controlling this subsystem
// here. Call these from Commands.
