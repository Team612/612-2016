#include "ShooterWheels.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalonLeft = RobotMap::leftFlywheel;
	CANTalonRight = RobotMap::rightFlywheel;
	this->hallCounterLeft = new PIDEdgeCounter(RobotMap::leftFlywheelHall);
	this->wheelControllerLeft = new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft, CANTalonLeft.get());
	this->hallCounterRight = new PIDEdgeCounter(RobotMap::rightFlywheelHall);
	this->wheelControllerRight = new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft, CANTalonRight.get());
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
