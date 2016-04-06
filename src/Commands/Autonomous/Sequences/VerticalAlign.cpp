#include "VerticalAlign.h"

VerticalAlign::VerticalAlign()
{
	Requires(Robot::shooterrotation.get());
}

void VerticalAlign::Initialize()
{
	AlignShooter();
}

void VerticalAlign::Execute()
{
	if (Robot::vision->GetTrackingID() != tID)
		AlignShooter();
}

bool VerticalAlign::IsFinished()
{
	return Robot::shooterrotation->OnTarget() || tID == -1;
}

void VerticalAlign::End()
{
	Robot::shooterrotation->PIDEnable(false);
}

void VerticalAlign::Interrupted()
{
	Robot::shooterrotation->PIDEnable(false);
}

void VerticalAlign::AlignShooter()
{
	int nID = Robot::vision->GetTrackingID();

	if (nID != -1)
	{
		std::shared_ptr<VisionTarget> target = Robot::vision->GetTrackedGoal();
		double angle = CalcAngle(target->GetDistance());
		Robot::shooterrotation->SetAngle(angle);
	}

	tID = nID;
}

double VerticalAlign::CalcAngle(double dist)
{
	double h = Robot::vision.get()->GetTrackedGoal()->GetHeight();
	double x = dist;//(0.0001592 * pow(h, 2)) - (0.06046*h) + 6.9204;
	SmartDashboard::PutNumber("Distance", x);
	double y = TARGET_HEIGHT_OFF_GROUND;
	double v = BOULDER_LAUNCH_SPEED;
	double g = 9.8; //gravity
	double sq = pow(v, 4) - (g * (g * (x * x) + 2 * y * (v * v)));

	sq = sqrt(abs(sq));

	double angleInRadians = atan(((v * v) - sq) / (g * x));
	double angleInDegrees = angleInRadians * (180 / M_PI);
	SmartDashboard::PutNumber("Calculated Angle", angleInDegrees);
	return angleInDegrees;
}
