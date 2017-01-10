#include <Commands/Shooter/ShooterManualControl.h>
#include "ShooterWheels.h"
#include "RobotMap.h"
#include <CANSpeedController.h>

ShooterWheels::ShooterWheels() :
		Subsystem("ShooterWheels")
{
	TalonSRXLeft = RobotMap::flywheelMotorL;
	TalonSRXRight = RobotMap::flywheelMotorR;
	shootertable = new NetworkTables();
	// TODO: Move these to RobotMap?
	this->hallCounterLeft.reset(new PIDEdgeCounter(RobotMap::flywheelHallL));
	this->hallCounterLeft->Reset();
	this->wheelControllerLeft.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->TalonSRXLeft.get()));
	this->wheelControllerLeft->SetTolerance(this->kTol);
	this->TalonSRXLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->TalonSRXRight->SetInverted(true);
	this->hallCounterRight.reset(new PIDEdgeCounter(RobotMap::flywheelHallR));
	this->wheelControllerRight.reset(new PIDController(this->kP, this->kI, this->kD, this->hallCounterLeft.get(), this->TalonSRXRight.get()));
	this->wheelControllerRight->SetTolerance(this->kTol);
    this->TalonSRXRight->SetControlMode(CANSpeedController::kPercentVbus);

}

void ShooterWheels::InitDefaultCommand()
{
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
		this->TalonSRXLeft->SetInverted(true);
		this->TalonSRXRight->SetInverted(false);
	}
	else
	{
		this->TalonSRXLeft->SetInverted(false);
		this->TalonSRXRight->SetInverted(true);
		speed = -speed;
	}
	this->wheelControllerLeft->SetSetpoint(speed);
	this->wheelControllerRight->SetSetpoint(speed);*/
}

float ShooterWheels::GetLeftWheelSpeed()
{
    return this->hallCounterLeft->Get();
}

float ShooterWheels::GetRightWheelSpeed()
{
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
		this->TalonSRXLeft->Disable();
		this->TalonSRXRight->Disable();
		this->TalonSRXLeft->SetControlMode(CANSpeedController::kVoltage);
		this->TalonSRXRight->SetControlMode(CANSpeedController::kVoltage);
		this->TalonSRXLeft->Set(0.0f);
		this->TalonSRXRight->Set(0.0f);
	}
	enabled = false;
}

void ShooterWheels::Enable()
{
	manualstarted = false;
	if(!enabled)
	{
		this->TalonSRXLeft->Enable();
		this->TalonSRXRight->Enable();
		this->TalonSRXLeft->SetControlMode(CANSpeedController::kPercentVbus);
		this->TalonSRXRight->SetControlMode(CANSpeedController::kPercentVbus);
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
	this->TalonSRXLeft->Enable();
	this->TalonSRXRight->Enable();
	this->TalonSRXLeft->SetControlMode(CANSpeedController::kPercentVbus);
	this->TalonSRXRight->SetControlMode(CANSpeedController::kPercentVbus);
}

void ShooterWheels::ManualSet(float speed)
{
	if(!manualstarted)
	{
		StartManual();
		printf("Starting Manual mode in set");
	}
	this->TalonSRXLeft->Set(speed);
	this->TalonSRXRight->Set(speed);
}
