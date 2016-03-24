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
	Robot::shooteractuator->SetPosition(position, solenoid);
}

void FireShooter::Execute()
{

}

bool FireShooter::IsFinished()
{
	return false;
}

void FireShooter::End()
{

}

void FireShooter::Interrupted()
{
	//std::printf("Warning: FireShooter interrupted.\n");
}
