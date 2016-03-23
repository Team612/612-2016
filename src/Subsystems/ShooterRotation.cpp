#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() : Subsystem("ShooterAngle")
{
	motor = RobotMap::shooterRotateMotor;
	motor->SetControlMode(CANSpeedController::kPercentVbus);
	absEncoder = RobotMap::shooterAbsEncoder.get();
	pid = new PIDControl(1, 0, 0, absEncoder, motor.get());
	pid->SetOutputRange(-1, 1);
	pid->SetInputRange(0, 5);
	this->HomePos();
	SmartDashboard::PutNumber("Gain Switch", gain_switch);
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
	motor->Set(gunner_axis);
}

void ShooterRotation::SetSetpoint(float set)
{
	// Gain scheduling
	if(pid->GetI() != 0)
		kI = pid->GetI();
	if(pid->GetD() != 0)
		kD = pid->GetD();

	bool limit_closed = (bool)(motor->IsFwdLimitSwitchClosed()) | (bool)(motor->IsRevLimitSwitchClosed());
	if(abs(pid->GetError()) > gain_switch || limit_closed)
	{
		pid->SetPID(pid->GetP(), 0, 0);
	}
	else
	{
		pid->SetPID(pid->GetP(), kI, kD);
	}

	pid->SetSetpoint(set);
}

// Button/Auto Control
void ShooterRotation::HomePos()
{
	if(!pid->IsEnabled())
		PIDEnable(true);
	SetSetpoint(HOME_SETPOINT);
}

void ShooterRotation::ShootPos(float angle)
{
	if(!pid->IsEnabled())
		PIDEnable(true);
	SetSetpoint(ConvertAngleToAbsolute(angle));
}

void ShooterRotation::IntakePos()
{
	if(!pid->IsEnabled())
		PIDEnable(true);
	SetSetpoint(INTAKE_SETPOINT);
}

void ShooterRotation::Stop()
{
	PIDEnable(false);
}

void ShooterRotation::PIDEnable(bool enabled)
{
	if(enabled) 
	{
		pid->Enable();
	}
	else
		pid->Disable();
}

void ShooterRotation::SmartDashboardOutput()
{
	SmartDashboard::PutNumber("Shooter Absolute Encoder", absEncoder->GetVoltageRound());
	SmartDashboard::PutNumber("Shooter Rotation Motor Out", pid->Get());
	SmartDashboard::PutData("PID Controller", pid);
	SmartDashboard::PutNumber("Shooter Rotation Error", pid->GetError());
	SmartDashboard::PutNumber("PID Integrated Error", pid->GetIntegratedError());
	gain_switch = SmartDashboard::GetNumber("Gain Switch", .6);
}
