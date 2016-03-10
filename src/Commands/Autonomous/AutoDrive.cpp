#include "AutoDrive.h"
#include "Robot.h"

AutoDrive::AutoDrive(int duration, float speed)
{
	time.reset(new Timer());
	this->speed = speed;
	this->duration = duration;
	Requires(Robot::drivetrain.get());
}

void AutoDrive::Initialize()
{
	time.get()->Start();
}

void AutoDrive::Execute()
{
	Robot::drivetrain.get()->SetArcadeDrive(speed, 0.0f);
}

bool AutoDrive::IsFinished()
{
	return (time.get()->Get() > duration);
}

void AutoDrive::End()
{
	Robot::drivetrain.get()->SetArcadeDrive(0.0f, 0.0f);
}

void AutoDrive::Interrupted()
{
	Robot::drivetrain.get()->SetArcadeDrive(0.0f, 0.0f);
	std::printf("ERROR: AutoDrive interrupted!");
}
