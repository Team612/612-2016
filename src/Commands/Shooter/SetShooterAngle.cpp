#include "SetShooterAngle.h"
#include "Robot.h"

SetShooterAngle::SetShooterAngle()
{
	//Set the angle to the calculated angle needed to make the goal
	Requires(Robot::shooterrotation.get());
	this->end_angle = CalcAngle();
}

SetShooterAngle::SetShooterAngle(float end_angle)
{
	/*
	 * This command can also be used to set for a specified angle
	 * Use this for shooter presets!
	 */
	Requires(Robot::shooterrotation.get());
	this->end_angle = end_angle;
}

void SetShooterAngle::Initialize()
{

}

void SetShooterAngle::Execute()
{
	Robot::shooterrotation.get()->SetAngle(end_angle);
}

bool SetShooterAngle::IsFinished()
{
	return Robot::shooterrotation.get()->OnTarget();
}

void SetShooterAngle::End()
{
	RobotMap::shooterRotateMotor.get()->Set(0.0f);
}

void SetShooterAngle::Interrupted()
{
	RobotMap::shooterRotateMotor.get()->Set(0.0f);
}

double SetShooterAngle::CalcAngle()
{
	double h = currentTarget->GetHeight();
	double x = (0.0001592 * pow(h, 2)) - (0.06046*h) + 6.9204;
	printf("\nDistance Calculation: %f", x);
	double y = TARGET_HEIGHT_OFF_GROUND;
	double v = BOULDER_LAUNCH_SPEED;
	double g = 9.8; //gravity
	double sq = pow(v, 4) - (g * (g * (x * x) + 2 * y * (v * v)));

	sq = sqrt(abs(sq));
	double angleInRadians = atan(((v * v) - sq) / (g * x));
	double angleInDegrees = angleInRadians * (180 / M_PI);
	printf("Degree Calculation: %f\n", angleInDegrees);
	return angleInDegrees;
}
