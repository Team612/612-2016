#include <Commands/Shooter/ShooterManuelControl.h>
#include "Robot.h"

ShooterManuelControl::ShooterManuelControl()
{
    Requires(Robot::shooterwheels.get());
}

// Called just before this Command runs the first time
void ShooterManuelControl::Initialize()
{
	Robot::shooterwheels->Disable();
	Robot::shooterwheels->StartManuel();
}

// Called repeatedly when this Command is scheduled to run
void ShooterManuelControl::Execute()
{
    auto gunner = -Robot::oi->getGunner()->GetRawAxis(1);
    if(gunner > TOLERANCE)
    {
    	printf("Fire\n");
        Fire();
    }
    else if (gunner < -TOLERANCE)
    {
    	printf("Intake\n");
        Intake();
    }
    else
    {
    	//printf("Stop\n");
        Stop();
    }

    //printf("Shooter\n");
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterManuelControl::IsFinished()
{
	//printf("Shooter IsFinished\n");
	return false;
}

// Called once after isFinished returns true
void ShooterManuelControl::End()
{
	printf("Ending");
	Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterManuelControl::Interrupted()
{
	printf("Interrupted");
    End();
}

void ShooterManuelControl::Fire()
{
	Robot::shooterwheels->ManuelSet(1);
}

void ShooterManuelControl::Intake()
{
	Robot::shooterwheels->ManuelSet(-.5);
}

void ShooterManuelControl::Stop()
{
	Robot::shooterwheels->ManuelSet(0);
}
