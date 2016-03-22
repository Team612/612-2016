#include "ShooterActuator.h"
#include "RobotMap.h"
#include <Commands/Shooter/FireShooter.h>

ShooterActuator::ShooterActuator() :
		Subsystem("ShooterActuator")
{
	actuator = RobotMap::shooterActuatorMotor;
	IR = RobotMap::shooterIR;
	storedposition = 0.0f;
	CanShoot = false;
}

void ShooterActuator::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	//SetDefaultCommand(new SetServoPosition(ShooterServoPosition::Neutral));
	SetDefaultCommand(new FireShooter(ShooterServoPosition::Neutral));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ShooterActuator::SetPosition(ShooterServoPosition position)
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

void ShooterActuator::SetPosition(float position)
{
	//This needs PID and is also unnecessary
	actuator->Set(position);
	this->storedposition = position;
}

/*void ShooterActuator::SetAngle(float angle)
{
	LeverServo->SetAngle(angle);
}*/

void ShooterActuator::SetClamp()
{
    this->SetPosition(this->CLAMP_SPEED);
}

void ShooterActuator::SetNeutral()
{
    this->SetPosition(this->NEUTRAL_SPEED);
}

void ShooterActuator::SetPush()
{
	this->SetPosition(this->PUSH_SPEED);
	if(CanShoot)
	{
		this->SetPosition(this->PUSH_SPEED);
	}
	else
		printf("Tried to shoot but not up to speed\n");
	printf("Tried to set servo to push\n");
}

float ShooterActuator::GetSpeed()
{
	return actuator->Get();
}

/*float ShooterActuator::GetAngle()
{
	return LeverServo->GetAngle();
}*/

/*std::shared_ptr<Servo> ShooterActuator::getLeverServo1()
{
	return LeverServo1;
}

std::shared_ptr<AnalogInput> ShooterActuator::getBallDetector()
{
	return RobotMap::ShooterActuatorDetect;
}*/

float ShooterActuator::getIRInInches()
{
	//SmartDashboard::PutNumber("Raw IR sensor voltage", irsensor->GetVoltage());
	std::printf("Raw IR sensor voltage: %f\n", IR->GetVoltage());
	//SmartDashboard::PutNumber("IR distance inches", ((27.86f * pow(irsensor->GetVoltage(), -1.15f)) * 0.393701f));
	std::printf("IR distance inches: %f\n", ((27.86f * pow(IR->GetVoltage(), -1.15f)) * 0.393701f));
	return ((27.86f * pow(IR->GetVoltage(), -1.15f)) * 0.393701f); //returns given IR value inches
}

bool ShooterActuator::AtSetPosition()
{
    return (actuator->Get() - storedposition) < 10E-2;
}
