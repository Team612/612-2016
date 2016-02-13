#include "Shifter.h"
#include "../RobotMap.h"

Shifter::Shifter() :
		Subsystem("Shifter")
{
	ShifterServo1 = RobotMap::ShifterServo1;
	ShifterServo2 = RobotMap::ShifterServo2;
}

void Shifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Shifter::SetShifter(float shiftPower)
{
	ShifterServo1->Set(shiftPower);
	ShifterServo2->Set(shiftPower);


}
float Shifter::GetShifter()
{
	 return (ShifterServo1->Get() + ShifterServo2 ->Get()) / 2;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
