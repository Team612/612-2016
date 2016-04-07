#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() : Subsystem("ShooterAngle")
{
	motor = RobotMap::shooterRotateMotor;
	motor->SetInverted(true);
	motor->SetControlMode(CANSpeedController::kPercentVbus);
	absEncoder = RobotMap::shooterAbsEncoder.get();
	pid = new PIDControl(kP, kI, kD, absEncoder, motor.get());
	pid->SetOutputRange(-.5, .5);
	pid->SetInputRange(0, 5);
	pid->SetContinuous(false);
	pid->SetAbsoluteTolerance(.1);
	this->HomePos();
	SmartDashboard::PutNumber("Gain Switch", gain_switch);
}

void ShooterRotation::SetAngle(double angle) //0-208.8 degrees
{
	PIDEnable(true);
	if (angle <= MAX_ANGLE && angle >= MIN_ANGLE)
	{
		pid->SetSetpoint(AngleToVolts(angle));
	}
}



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
	/*
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
	*/

	pid->SetSetpoint(set);
}

// Button/Auto Control
void ShooterRotation::HomePos()
{
	if(!pid->IsEnabled())
		PIDEnable(true);
	SetAngle(HOME_ANGLE);
}

void ShooterRotation::IntakePos()
{
	if(!pid->IsEnabled())
		PIDEnable(true);
	SetAngle(INTAKE_ANGLE);
}

void ShooterRotation::Stop()
{
	PIDEnable(false);
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
	//SmartDashboard::PutNumber("PID Integrated Error", pid->GetIntegratedError());
	gain_switch = SmartDashboard::GetNumber("Gain Switch", .6);
}

bool ShooterRotation::OnTarget()
{
	return pid->OnTarget();
}

/*PIDControl* ShooterRotation::getShooterPID()
{
	return pid;
}*/
