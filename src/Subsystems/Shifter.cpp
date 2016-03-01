#include "Shifter.h"
#include "../RobotMap.h"

Shifter::Shifter() :
		Subsystem("Shifter")
{
	ShifterServo1 = RobotMap::shifterServo1;
	ShifterServo2 = RobotMap::shifterServo2;
}

void Shifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void Shifter::Set(float shiftPower)
{
	ShifterServo1->Set(shiftPower);
	ShifterServo2->Set(shiftPower);

	SmartDashboard::PutNumber("Servo 1", ShifterServo1->Get());
	SmartDashboard::PutNumber("Servo 2", ShifterServo2->Get());
}
float Shifter::Get()
{
	 return (ShifterServo1->Get() + ShifterServo2 ->Get()) / 2;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
