#include "ShooterRotation.h"
#include "RobotMap.h"
#include "Commands/Shooter/ShooterJoystick.h"

ShooterRotation::ShooterRotation() : Subsystem("ShooterRotation")//:
	//	PIDSubsystem("ShooterRotation", 0.01, 0.0001, 0.005)
{
	RotateMotor = RobotMap::shooterRotateMotor;
	////RotateMotor->SetControlMode(CANSpeedController::kVoltage);
	////RotateMotor->SetFeedbackDevice(CANTalon::AnalogEncoder);
	////RotateMotor->SetPID(1.0, 0, 0);
	//GetPIDController()->SetOutputRange(-1.0, 1.0);
	//GetPIDController()->SetSetpoint(AngleToVolts(angle));
//	GetPIDController()->SetPercentTolerance(5);

}

void ShooterRotation::SetAngle(double angle)
{
	std::printf("sets angle\n");
	this->angle = angle;
	RotateMotor->Set(AngleToVolts(angle));
}



//double ShooterRotation::ReturnPIDInput()
//{
//	GetPIDController()->SetSetpoint(AngleToVolts(angle));
//	return (double)RobotMap::shooterEncoder->GetVoltage();
//}

//void ShooterRotation::UsePIDOutput(double output)
//{
//	RotateMotor->Set(output);
//}

void ShooterRotation::IncrementAngle(double inc)
{
	double newAngle = angle + inc;
	if (newAngle >= MIN_ANGLE && newAngle <= MAX_ANGLE)
	SetAngle(angle + 1);
}

void ShooterRotation::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ShooterJoystick());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

float ShooterRotation::GetSpeed()
{
	return RotateMotor->Get();
}

void ShooterRotation::SetSpeed(float speed)
{
	RotateMotor->Set(speed);
	SmartDashboard::PutNumber("Rotation Speed", RotateMotor->Get());
}

void ShooterRotation::ShooterHome()
{
	SetAngle(HOME_POS);
}

void ShooterRotation::SetMode(CANTalon::ControlMode mode)
{
	RotateMotor->SetControlMode(mode);
}

double ShooterRotation::AngleToVolts(double angle) {
	double volts = (5*angle) / 360;
	return volts;
}
