#include "ShooterLever.h"
#include "../RobotMap.h"

ShooterLever::ShooterLever() :
		Subsystem("ShooterLever")
{
	LeverServo1 = RobotMap::shooterLeverServo1;
}

void ShooterLever::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ShooterLever::SetServoPosition(float position)
{
    LeverServo1->Set(position);
}

void ShooterLever::SetServoAngle(float angle)
{
    LeverServo1->SetAngle(angle);
}

float ShooterLever::GetServoPosition()
{
    return LeverServo1->Get();
}

float ShooterLever::GetServoAngle()
{
    return LeverServo1->GetAngle();
}
