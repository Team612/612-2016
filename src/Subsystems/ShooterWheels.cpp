#include <Commands/Shooter/ShooterManualControl.h>
#include "ShooterWheels.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterControl.h"

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	CANTalonLeft = RobotMap::flywheelMotorL;
	CANTalonRight = RobotMap::flywheelMotorR;
	shootertable = new NetworkTables();
	// TODO: Move these to RobotMap?
	this->hallCounterLeft.reset(new PIDEdgeCounter(RobotMap::flywheelHallL));
	this->hallCounterLeft->Reset();
	this->wheelControllerLeft.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonLeft.get()));
	this->wheelControllerLeft->SetTolerance(this->kTol);
	this->CANTalonLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->CANTalonLeft->SetInverted(true);
	this->hallCounterRight.reset(new PIDEdgeCounter(RobotMap::flywheelHallR));
	this->wheelControllerRight.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->CANTalonRight.get()));
	this->wheelControllerRight->SetTolerance(this->kTol);
    this->CANTalonRight->SetControlMode(CANSpeedController::kPercentVbus);

}

void ShooterWheels::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShooterManualControl());

}

void ShooterWheels::SetWheelSpeed(float speed)
{
	/*
	if(!this->enabled)
	{
		Enable();
		printf("Enabling shooter wheel PID implicitly\n");
	}
	if(speed > 0)
	{
		this->CANTalonLeft->SetInverted(true);
		this->CANTalonRight->SetInverted(false);
	}
	else
	{
		this->CANTalonLeft->SetInverted(false);
		this->CANTalonRight->SetInverted(true);
		speed = -speed;
	}
	this->wheelControllerLeft->SetSetpoint(speed);
	this->wheelControllerRight->SetSetpoint(speed);*/
}

float ShooterWheels::GetLeftWheelSpeed()
{
//	return this->wheelControllerLeft->Get();
    return this->hallCounterLeft->Get();
}

float ShooterWheels::GetRightWheelSpeed()
{
    //return this->wheelControllerRight->Get();
    return this->hallCounterRight->Get();
}

bool ShooterWheels::UpToSpeed()
{
	shootertable->AddValue(this->hallCounterLeft->Get());
    return this->wheelControllerLeft->OnTarget() && this->wheelControllerRight->OnTarget();
}

void ShooterWheels::Disable()
{
	if(enabled)
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
	enabled = false;
}

void ShooterWheels::Enable()
{
	manualstarted = false;
	if(!enabled)
	{
		this->CANTalonLeft->Enable();
		this->CANTalonRight->Enable();
		this->CANTalonLeft->SetControlMode(CANSpeedController::kPercentVbus);
		this->CANTalonRight->SetControlMode(CANSpeedController::kPercentVbus);
		this->wheelControllerLeft->SetOutputRange(-1.00f, 1.00f);
		this->wheelControllerRight->SetOutputRange(-1.00f, 1.00f);
		this->wheelControllerLeft->Enable();
		this->wheelControllerRight->Enable();
	}
	enabled = true;
}

void ShooterWheels::StartManual()
{
	manualstarted = true;
	this->CANTalonLeft->Enable();
	this->CANTalonRight->Enable();
	this->CANTalonLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->CANTalonRight->SetControlMode(CANSpeedController::kPercentVbus);
}

void ShooterWheels::ManualSet(float speed)
{
	if(!manualstarted) { StartManual(); printf("Starting Manual mode in set"); }
	this->CANTalonLeft->Set(speed);
	this->CANTalonRight->Set(speed);
}
