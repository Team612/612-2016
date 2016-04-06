#include "SetShooterAngle.h"
#include "Robot.h"

SetShooterAngle::SetShooterAngle()
{
	SetShooterAngle(Robot::shooterrotation->HOME_ANGLE);
}

SetShooterAngle::SetShooterAngle(float end_angle)
{
	Requires(Robot::shooterrotation.get());
	this->end_angle = end_angle;
}

void SetShooterAngle::Initialize()
{
	Robot::shooterrotation.get()->SetAngle(end_angle);
}

void SetShooterAngle::Execute() {}

bool SetShooterAngle::IsFinished()
{
	return Robot::shooterrotation.get()->OnTarget();
}

void SetShooterAngle::End()
{
	Robot::shooterrotation->PIDEnable(false);
}

void SetShooterAngle::Interrupted()
{
	Robot::shooterrotation->PIDEnable(false);
}
