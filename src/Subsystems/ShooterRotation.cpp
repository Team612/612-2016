#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() : Subsystem("ShooterRotation")
//PIDSubsystem("ShooterRotation", 0.01, 0.0001, 0.005)
{
	RotateMotor = RobotMap::shooterRotateMotor;
	RotateMotor->SetControlMode(CANSpeedController::kVoltage);
	RotateMotor->SetFeedbackDevice(CANTalon::AnalogEncoder);
	RotateMotor->SetPID(0.01, 0.0001, 0.005);
	//RotateMotor->SetOutputRange(-1.0, 1.0);
	/*GetPIDController()->SetInputRange(MIN_VOLTS, MAX_VOLTS);
	GetPIDController()->SetPercentTolerance(5);*/

}

void ShooterRotation::SetPosition(double pos) //1.1 - 4
{
	std::printf("sets angle\n");
	this->pos = pos;
	RotateMotor->Set(pos);
}



/*double ShooterRotation::ReturnPIDInput()
{
	return (double) RotateMotor->GetAnalogIn();
}

void ShooterRotation::UsePIDOutput(double output)
{
	RotateMotor->Set(output);
}*/

void ShooterRotation::IncrementAngle(double inc)
{
	double newAngle = pos + inc;
	if (newAngle >= MIN_VOLTS && newAngle <= MAX_VOLTS)
	SetPosition(pos + .1);
}

void ShooterRotation::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterJoystick());
}

float ShooterRotation::GetSpeed()
{
	return RotateMotor->Get();
}

void ShooterRotation::SetSpeed(float speed)
{
	RotateMotor->Set(speed);
}

void ShooterRotation::ShooterHome()
{
	SetPosition(HOME_POS);
}

void ShooterRotation::SetMode(CANTalon::ControlMode mode)
{
	RotateMotor->SetControlMode(mode);
}

/*
double ShooterRotation::AngleToVolts(double angle)
{
	//TODO: Fix!!
	double volts = (5*angle) / 360;
	return volts;
}*/
