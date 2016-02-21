#include "FireShooter.h"
#include "Robot.h"

FireShooter::FireShooter()
{

	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
    Requires(Robot::shooterwheels.get());
    Requires(Robot::shooterlever.get());
}

// Called just before this Command runs the first time
void FireShooter::Initialize()
{
	std::printf("FIRESHOOTER\n");
	Robot::shooterwheels->setWheelSpeed(RobotMap::flywheelShootSpeed);
    Robot::shooterlever->SetClamp();
}

// Called repeatedly when this Command is scheduled to run
void FireShooter::Execute()
{
    if(Robot::shooterwheels->upToSpeed())
    {
        Robot::shooterlever->SetPush();
        this->fired = true;
    }
}

// Make this return true when this Command no longer needs to run execute()
bool FireShooter::IsFinished()
{
	return this->fired;
}

// Called once after isFinished returns true
void FireShooter::End()
{
	Robot::shooterwheels->setWheelSpeed(0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireShooter::Interrupted()
{

}
