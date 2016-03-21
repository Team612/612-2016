#ifndef SetShooterAngle_H
#define SetShooterAngle_H

#include "Commands/PIDCommand.h"
#include "WPILib.h"

#include "VisionTarget.h"

class SetShooterAngle: public Command
{
public:
	SetShooterAngle(float end_angle);
	SetShooterAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float end_angle;
	bool target_exists;

	//std::shared_ptr<VisionTarget> currentTarget;

	const float STARTING_ANGLE = 0.0f;
	const float SPEED = 0.7f;
	const double TARGET_HEIGHT = 0.305; //in meters
	const double TARGET_WIDTH  = 0.506; //in meters
	const double TARGET_HEIGHT_OFF_GROUND = 2; //in meters
	const double BOULDER_LAUNCH_SPEED = 12.9; //in meters per second
	const double TARGET_ASPECT = 1.66/1.00;

	double CalcAngle();
};

#endif
