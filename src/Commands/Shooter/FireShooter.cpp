#include "FireShooter.h"

FireShooter::FireShooter(ShooterActuatorPosition pos, bool solenoid)
{
    Requires(Robot::shooteractuator.get());
    this->position = pos;

    this->solenoid = solenoid;
}

// Called just before this Command runs the first time
void FireShooter::Initialize()
{
	//std::printf("Info: FireShooter initialized\n");
	Robot::shooteractuator->SetPosition(position, solenoid);
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
		if(RobotMap::shooterActuatorMotor.get()->Get() > 0.1)
			return true;
	}
	else
	{
		return false;
	}
}

void FireShooter::End()
{
	//std::printf("Info: FireShooter end\n");
}

void FireShooter::Interrupted()
{
	//std::printf("Warning: FireShooter interrupted.\n");
}
