#include "ShooterWheels.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalon1 = RobotMap::leftFlywheel;
	CANTalon2 = RobotMap::rightFlywheel;
	this->hallCounterLeft = new PIDEdgeCounter(RobotMap::leftFlywheelHall);
	this->wheelControllerLeft = new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft);
}

void ShooterWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

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



