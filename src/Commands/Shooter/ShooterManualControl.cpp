#include <Commands/Shooter/ShooterManualControl.h>
#include "Robot.h"

ShooterManualControl::ShooterManualControl()
{
    Requires(Robot::shooterwheels.get());
}

// Called just before this Command runs the first time
void ShooterManualControl::Initialize()
{
	Robot::shooterwheels->Disable();
	Robot::shooterwheels->StartManual();
}

// Called repeatedly when this Command is scheduled to run
void ShooterManualControl::Execute()
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
bool ShooterManualControl::IsFinished()
{
	//printf("Shooter IsFinished\n");
	return false;
}

// Called once after isFinished returns true
void ShooterManualControl::End()
{
	printf("Ending");
	Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterManualControl::Interrupted()
{
	printf("Interrupted");
    End();
}

void ShooterManualControl::Fire()
{
	Robot::shooterwheels->ManualSet(1);
}

void ShooterManualControl::Intake()
{
	Robot::shooterwheels->ManualSet(-.5);
}

void ShooterManualControl::Stop()
{
	Robot::shooterwheels->ManualSet(0);
}
