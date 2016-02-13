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
	SetDefaultCommand(new AutoServo());
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

/*std::shared_ptr<Servo> ShooterLever::getLeverServo1()
{
	return LeverServo1;
}

std::shared_ptr<AnalogInput> ShooterLever::getBallDetector()
{
	return RobotMap::shooterLeverDetect;
}*/

float ShooterLever::getIRInInches(AnalogInput* ir)
{
	return ((27.86f * pow(ir->GetVoltage(), -1.15f)) * 0.393701f); //returns given IR value inches
}
