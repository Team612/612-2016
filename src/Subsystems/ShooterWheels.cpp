#include "ShooterWheels.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterControl.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalonLeft = RobotMap::leftFlywheel;
	CANTalonRight = RobotMap::rightFlywheel;
	this->hallCounterLeft.reset(new PIDEdgeCounter(RobotMap::leftFlywheelHall));
	this->wheelControllerLeft.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonLeft.get()));
	this->wheelControllerLeft->SetTolerance(this->kTol);
	this->CANTalonLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->CANTalonLeft->SetInverted(true);
	this->hallCounterRight.reset(new PIDEdgeCounter(RobotMap::rightFlywheelHall));
	this->wheelControllerRight.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonRight.get()));
	this->wheelControllerRight->SetTolerance(this->kTol);
    this->CANTalonRight->SetControlMode(CANSpeedController::kPercentVbus);
}

void ShooterWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShooterControl());

}

void ShooterWheels::SetWheelSpeed(float speed)
{
    this->wheelControllerLeft->Enable();
    this->wheelControllerLeft->SetOutputRange(-1.00f, 1.00f);
    this->wheelControllerLeft->SetSetpoint(speed);
    this->wheelControllerRight->Enable();
    this->wheelControllerRight->SetOutputRange(-1.00f, 1.00f);
    this->wheelControllerRight->SetSetpoint(speed);
}

float ShooterWheels::GetLeftWheelSpeed()
{
	return this->wheelControllerLeft->Get();
}

float ShooterWheels::GetRightWheelSpeed()
{
    return this->wheelControllerRight->Get();
}

bool ShooterWheels::UpToSpeed()
{
    if(std::fabs(this->leftLastErr - this->wheelControllerLeft->GetAvgError()) < 1.0f || std::fabs(this->rightLastErr - this->wheelControllerRight->GetAvgError()) < 1.0f)
    {
        std::printf("Left: %f %f\n", this->wheelControllerLeft->GetAvgError(), this->wheelControllerLeft->GetSetpoint());
        std::printf("Right: %f %f\n", this->wheelControllerRight->GetAvgError(), this->wheelControllerRight->GetSetpoint());
        std::printf("upToSpeed %i\n", this->wheelControllerLeft->OnTarget() && this->wheelControllerRight->OnTarget());
        this->leftLastErr = this->wheelControllerLeft->GetAvgError();
        this->rightLastErr = this->wheelControllerRight->GetAvgError();
    }
    std::printf("Left: %f %f\n", this->wheelControllerLeft->GetError());//, this->wheelControllerLeft->GetAvgError());
    std::printf("Right: %f %f\n", this->wheelControllerRight->GetError());//, this->wheelControllerRight->GetAvgError());
    return this->wheelControllerLeft->OnTarget() && this->wheelControllerRight->OnTarget();
}

void ShooterWheels::Disable()
{
	this->wheelControllerLeft->Disable();
	this->wheelControllerRight->Disable();
	this->CANTalonLeft->Disable();
	this->CANTalonRight->Disable();
	this->CANTalonLeft->SetControlMode(CANSpeedController::kVoltage);
	this->CANTalonRight->SetControlMode(CANSpeedController::kVoltage);
	this->CANTalonLeft->Set(0.0f);
	this->CANTalonRight->Set(0.0f);

}

void ShooterWheels::Enable()
{
	this->CANTalonLeft->Enable();
	this->CANTalonRight->Enable();
	this->CANTalonLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->CANTalonRight->SetControlMode(CANSpeedController::kPercentVbus);
	this->wheelControllerLeft->Enable();
	this->wheelControllerRight->Enable();
}
