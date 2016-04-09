#include "DriveJoystick.h"
#include <cmath>

DriveJoystick::DriveJoystick() :
		Command()
{
	Requires(Robot::drivetrain.get());

	leftPos = 0.0f;
	rightPos = 0.0f;
}
void DriveJoystick::Initialize()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
}

void DriveJoystick::Execute()
{
	Robot::drivetrain->GetEncoderDistance();

	if(Robot::getInstance().IsOperatorControl())
	{
		if (Robot::oi->getDriver()->GetRawAxis(3) <= 0.1)
		{
			Robot::drivetrain->SetTankDrive(Robot::oi->getDriver()->GetRawAxis(1),
					Robot::oi->getDriver()->GetRawAxis(5));
			Robot::inverted = false;
		}
		else
		{
			Robot::drivetrain->SetTankDrive(
					Robot::oi->getDriver()->GetRawAxis(5) * -1,
					Robot::oi->getDriver()->GetRawAxis(1) * -1);
			Robot::inverted = true;
		}
		
	}
}

bool DriveJoystick::IsFinished()
{
	return false;
}

void DriveJoystick::End()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
}
void DriveJoystick::Interrupted()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
	std::printf("Warning: DriveJoystick interrupted!\n");
}
