#include "ShooterWheels.h"
#include "../RobotMap.h"
#include "../Commands/AutoWheels.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalonLeft = RobotMap::leftFlywheel;
	CANTalonRight = RobotMap::rightFlywheel;
	this->hallCounterLeft.reset(new PIDEdgeCounter(RobotMap::leftFlywheelHall));
	this->wheelControllerLeft.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonLeft.get()));
	this->wheelControllerLeft->SetTolerance(this->kTol);
	this->CANTalonLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->hallCounterRight.reset(new PIDEdgeCounter(RobotMap::rightFlywheelHall));
	this->wheelControllerRight.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonRight.get()));
	this->wheelControllerRight->SetTolerance(this->kTol);
    this->CANTalonRight->SetControlMode(CANSpeedController::kPercentVbus);
}

void ShooterWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new AutoWheels());

}
void ShooterWheels::setWheelSpeed(float speed)
{
    this->wheelControllerLeft->Enable();
    this->wheelControllerLeft->SetOutputRange(-1.00f, 1.00f);
    this->wheelControllerLeft->SetSetpoint(speed);
    this->wheelControllerRight->Enable();
    this->wheelControllerRight->SetOutputRange(-1.00f, 1.00f);
    this->wheelControllerRight->SetSetpoint(speed);
}

float ShooterWheels::getLeftWheelSpeed()
{
	return this->wheelControllerLeft->Get();
}

float ShooterWheels::getRightWheelSpeed()
{
    return this->wheelControllerRight->Get();
}

bool ShooterWheels::upToSpeed()
{
	std::printf("Left: %f %f\n", this->wheelControllerLeft->GetError(), this->wheelControllerLeft->GetSetpoint());
	std::printf("Right: %f %f\n", this->wheelControllerRight->GetError(), this->wheelControllerRight->GetSetpoint());
	std::printf("upToSpeed %i\n", this->wheelControllerLeft->OnTarget() && this->wheelControllerRight->OnTarget());
	//std::printf("Left: %f %f\n", this->wheelControllerLeft->GetError(), this->wheelControllerLeft->GetAvgError());
    //std::printf("RightEror: %f %f\n", this->wheelControllerRight->GetError(), this->wheelControllerRight->GetAvgError());
    return this->wheelControllerLeft->OnTarget() && this->wheelControllerRight->OnTarget();
}
