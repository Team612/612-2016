#include "Arm.h"
#include "RobotMap.h"
#include "Commands/Arm/ArmMove.h"


Arm::Arm() :
		PIDSubsystem("Arm", 1.0, 0.0, 0,0) //TODO: Tuning!
{
	adjust = RobotMap::armAdjust;
	rotationDetect = RobotMap::armRotationDetect;
	GetPIDController()->SetOutputRange(-1.0f, 1.0f);
	GetPIDController()->SetInputRange(MIN_VOLTS, MAX_VOLTS);

	GetPIDController()->SetSetpoint(MIN_VOLTS);
	Enable();
}

void Arm::InitDefaultCommand()
{
	SetDefaultCommand(new ArmMove());
}

void Arm::SetMode(CANTalon::ControlMode mode)
{
	adjust->SetControlMode(mode);
}

void Arm::UsePIDOutput(double output)
{
	adjust->Set(output);
}

double Arm::ReturnPIDInput()
{
	return rotationDetect->GetVoltage();
}

void Arm::SetArmPosition(double position)
{
	GetPIDController()->SetSetpoint(position);
	Enable();
}

void Arm::SetArmSpeed(double speed)
{
	adjust->Set(speed);
}
