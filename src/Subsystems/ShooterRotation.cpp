#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() : Subsystem("ShooterAngle")
{
	motor = RobotMap::shooterRotateMotor;
	absEncoder = RobotMap::shooterAbsEncoder.get();
	pid = new PIDController(kP, kI, kD, absEncoder, motor.get());
	pid->SetOutputRange(-1, 1);
	pid->SetInputRange(0, 5);
	pid->SetSetpoint(HOME_SETPOINT);
	pid->SetContinuous(true);
}

//void ShooterRotation::SetAngle(double pos) //0-208.8 degrees
//{
	/*
	std::printf("sets angle\n");
	this->pos = pos;
	double angle = pos + MIN_ANGLE;
	if (angle < MAX_ANGLE && angle > MIN_ANGLE)
		GetPIDController()->SetSetpoint(AngleToVolts(angle));

#ifdef DEBUG
	std::printf("Angle: %f\n", angle);
	std::printf("Voltage: %f\n", AngleToVolts(angle));
#endif
*/
//}

void ShooterRotation::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterJoystick());
}

// Teleop Axis Control
void ShooterRotation::Gun(float gunner_axis)
{
	
}

// Button/Auto Control
void ShooterRotation::HomePos()
{
	
}

void ShooterRotation::ShootPos(float angle)
{
	pid->SetSetpoint(ConvertAngleToAbsolute(angle));
}

void ShooterRotation::IntakePos()
{
	
}

void ShooterRotation::Stop()
{
	pid->Disable();
}

void ShooterRotation::PIDEnable(bool enabled)
{
	if(enabled)
		pid->Enable();
	else
		pid->Disable();
}

void ShooterRotation::SmartDashboardOutput()
{
	SmartDashboard::PutNumber("Shooter Absolute Encoder", absEncoder->GetVoltageRound());
	SmartDashboard::PutNumber("Shooter Rotation Motor Out", pid->Get());
	SmartDashboard::PutData("PID Controller", pid);
	SmartDashboard::PutNumber("Shooter Rotation Error", pid->GetError());
}