#include "SetShooterAngle.h"
#include "Robot.h"


SetShooterAngle::SetShooterAngle(float end_angle, float timeout = 0)
{
	Requires(Robot::shooterrotation.get());
	this->end_angle = end_angle;
	if(timeout != 0)
		SetTimeout(timeout);
}

void SetShooterAngle::Initialize()
{
	Robot::shooterrotation->PIDEnable(true);
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
	Robot::shooterrotation->Gun(0);
}

