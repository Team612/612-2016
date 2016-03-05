#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() : PIDSubsystem("ShooterRotation", 15, 10, 10)
{
	RotateMotor = RobotMap::shooterRotateMotor;
	GetPIDController()->SetOutputRange(-1.0, 1.0);
	GetPIDController()->SetInputRange(MIN_VOLTS, MAX_VOLTS);
	GetPIDController()->SetSetpoint(HOME_POS);
	GetPIDController()->SetAbsoluteTolerance(AngleToVolts(3));
	GetPIDController()->Enable();
}

void ShooterRotation::SetAngle(double pos) //0-208.8 degrees
{
	std::printf("sets angle\n");
	this->pos = pos;
	double angle = pos + MIN_ANGLE;
	if (angle < MAX_ANGLE && angle > MIN_ANGLE)
		GetPIDController()->SetSetpoint(AngleToVolts(angle));

#ifdef DEBUG
	std::printf("Angle: %f\n", angle);
	std::printf("Voltage: %f\n", AngleToVolts(angle));
#endif
}

double ShooterRotation::ReturnPIDInput()
{
#ifdef DEBUG
	std::printf("Shooter Voltage: %f\n", RobotMap::shooterEncoder->GetVoltage());
#endif
	return (double) RobotMap::shooterEncoder->GetVoltage();
}

void ShooterRotation::UsePIDOutput(double output)
{
	RotateMotor->Set(-output);
	SmartDashboard::PutNumber("PID Rotation", output);
	SmartDashboard::PutNumber("Shooter Angle", RobotMap::shooterEncoder->GetVoltage() * 360 / 5);
#ifdef DEBUG
	std::printf("Shooter PID Output: %f\n", output);
#endif
}

void ShooterRotation::IncrementAngle(double inc)
{
	double newAngle = pos + inc;
	SetAngle(newAngle);
}

void ShooterRotation::SetPIDEnabled(bool enabled)
{
	if(enabled)
		GetPIDController()->Enable();
	else
	{
		GetPIDController()->Disable();
		SetSpeed(0.0);
	}
}

void ShooterRotation::SetPID(double p, double i, double d)
{
	GetPIDController()->SetPID(p, i, d);
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
	SmartDashboard::PutNumber("Rotation Speed", RotateMotor->Get());
}

void ShooterRotation::SetMode(CANTalon::ControlMode mode)
{
	RotateMotor->SetControlMode(mode);
}

double ShooterRotation::AngleToVolts(double angle)
{
	double volts = (5*angle) / 360;
	return volts;
}
