#include "ShooterLever.h"
#include "RobotMap.h"
#include <Commands/Shooter/FireShooter.h>

ShooterLever::ShooterLever() :
		Subsystem("ShooterLever")
{
	LeverServo = RobotMap::shooterLeverServo1;
	irsensor = RobotMap::shooterLeverDetect;
	storedposition = 0.0f;
	CanShoot = false;
}

void ShooterLever::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new SetServoPosition(ShooterServoPosition::Neutral));
	SetDefaultCommand(new FireShooter(ShooterServoPosition::Neutral));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ShooterLever::SetPosition(ShooterServoPosition position)
{
	switch(position)
	{
		case Clamp:
			SetClamp();
			break;
		case Neutral:
			SetNeutral();
			break;
		case Push:
			SetPush();
			CanShoot = false;
			break;
		default:
			printf("Trying to set shooter lever servo position to an invalid or not defined value!");
			break;
	}
}

void ShooterLever::SetPosition(float position)
{
	LeverServo->Set(position);
	this->storedposition = position;
}

/*void ShooterLever::SetAngle(float angle)
{
	LeverServo->SetAngle(angle);
}*/

void ShooterLever::SetClamp()
{
    this->SetPosition(this->CLAMP_POS);
}

void ShooterLever::SetNeutral()
{
    this->SetPosition(this->NEUTRAL_POS);
}

void ShooterLever::SetPush()
{
	this->SetPosition(this->PUSH_POS);
	if(CanShoot)
	{
		this->SetPosition(this->PUSH_POS);
	}
	else
		printf("Tried to shoot but not up to speed\n");
	printf("Tried to set servo to push\n");
}

float ShooterLever::GetPosition()
{
	return LeverServo->Get();
}

/*float ShooterLever::GetAngle()
{
	return LeverServo->GetAngle();
}*/

/*std::shared_ptr<Servo> ShooterLever::getLeverServo1()
{
	return LeverServo1;
}

std::shared_ptr<AnalogInput> ShooterLever::getBallDetector()
{
	return RobotMap::shooterLeverDetect;
}*/

float ShooterLever::getIRInInches()
{
	SmartDashboard::PutNumber("Raw IR sensor voltage", irsensor->GetVoltage());
	std::printf("Raw IR sensor voltage: %f\n", irsensor->GetVoltage());
	SmartDashboard::PutNumber("IR distance inches", ((27.86f * pow(irsensor->GetVoltage(), -1.15f)) * 0.393701f));
	std::printf("IR distance inches: %f\n", ((27.86f * pow(irsensor->GetVoltage(), -1.15f)) * 0.393701f));
	return ((27.86f * pow(irsensor->GetVoltage(), -1.15f)) * 0.393701f); //returns given IR value inches
}

bool ShooterLever::AtSetPosition()
{
    return (LeverServo->Get() - storedposition) < 10E-2;
}
