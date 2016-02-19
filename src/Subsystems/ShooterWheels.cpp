#include "ShooterWheels.h"
#include "../RobotMap.h"
#include "../Commands/AutoWheels.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalon1 = RobotMap::leftFlywheel;
	CANTalon2 = RobotMap::rightFlywheel;
}

void ShooterWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new AutoWheels());

}
void ShooterWheels::setWheelSpeed(float speed)
{
	CANTalon1->Set(speed);
	CANTalon2->Set(speed);
}

float ShooterWheels::getLeftWheelSpeed()
{
	return 	CANTalon1->Get();
}

float ShooterWheels::getRightWheelSpeed()
{
	return 	CANTalon2->Get();
}



