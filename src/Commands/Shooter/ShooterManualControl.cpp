#include <Commands/Shooter/ShooterManualControl.h>
#include "Robot.h"

ShooterManualControl::ShooterManualControl()
{
    Requires(Robot::shooterwheels.get());
}

void ShooterManualControl::Initialize()
{
	Robot::shooterwheels->Disable();
	Robot::shooterwheels->StartManual();
}

void ShooterManualControl::Execute()
{
    if(Robot::getInstance().IsOperatorControl())
    {
        auto gunner = -Robot::oi->getGunner()->GetRawAxis(1);
        if(gunner > TOLERANCE)
        {
            Fire();
        }
        else if (gunner < -TOLERANCE)
        {
            Intake();
        }
        else
        {
            Stop();
        }
    }
}

bool ShooterManualControl::IsFinished()
{
	return false;
}

void ShooterManualControl::End()
{
	printf("Ending");
	Stop();
}

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
	Robot::shooterwheels->ManualSet(-1);
}

void ShooterManualControl::Stop()
{
	Robot::shooterwheels->ManualSet(0);
}
