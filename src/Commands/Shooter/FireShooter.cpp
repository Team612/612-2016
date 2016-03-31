#include "FireShooter.h"

FireShooter::FireShooter(ShooterActuatorPosition pos, bool solenoid)
{
    Requires(Robot::shooteractuator.get());
    this->position = pos;

    this->solenoid = solenoid;
}

void FireShooter::Initialize()
{
	//std::printf("Info: FireShooter initialized\n");
	if((int) RobotMap::shooterActuatorLSwitch.get()->Get() == 0)
	{
		printf("Info: Tried to shoot but at limit switch\n");
		Robot::shooteractuator->SetPosition(ShooterActuatorPosition::Neutral, solenoid);
	}
	else
	{
		printf("Info: Normal shooting\n");
		Robot::shooteractuator->SetPosition(position, solenoid);
	}

}

void FireShooter::Execute()
{

}

bool FireShooter::IsFinished()
{
	if(solenoid)
	{
		if(RobotMap::shooterSpike.get()->Get() == Relay::Value::kForward)
			return true;
	}
	else if(!solenoid)
	{
		//if(RobotMap::shooterActuatorMotor.get()->Get() > 0.1)
			return true;
	}
	return false; // The compiler needs this
}

void FireShooter::End()
{
	//std::printf("Info: FireShooter end\n");
}

void FireShooter::Interrupted()
{
	//std::printf("Warning: FireShooter interrupted.\n");
}
