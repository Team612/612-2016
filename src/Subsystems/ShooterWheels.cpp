#include "ShooterWheels.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalonLeft = RobotMap::leftFlywheel;
	CANTalonRight = RobotMap::rightFlywheel;
	this->hallCounterLeft.reset(new PIDEdgeCounter(RobotMap::leftFlywheelHall));
	this->wheelControllerLeft.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonLeft.get()));
	this->hallCounterRight.reset(new PIDEdgeCounter(RobotMap::rightFlywheelHall));
	this->wheelControllerRight.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonRight.get()));
}

void ShooterWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}
void ShooterWheels::setWheelSpeed(float speed)
{
    wheelControllerLeft->Enable();
    wheelControllerLeft->SetOutputRange(-1.00, 1.00);
    wheelControllerLeft->SetSetpoint(speed);
    wheelControllerRight->Enable();
    wheelControllerRight->SetOutputRange(-1.00, 1.00);
    wheelControllerRight->SetSetpoint(speed);
}

float ShooterWheels::getLeftWheelSpeed()
{
	return wheelControllerLeft->Get();
}

float ShooterWheels::getRightWheelSpeed()
{
	return 	wheelControllerRight->Get();
}
