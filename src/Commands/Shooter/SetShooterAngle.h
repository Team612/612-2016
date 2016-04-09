#ifndef SetShooterAngle_H
#define SetShooterAngle_H

#include "Commands/PIDCommand.h"
#include "WPILib.h"

#include "VisionTarget.h"

class SetShooterAngle: public Command
{
public:
	SetShooterAngle(float end_angle, float timeout = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float end_angle;

};

#endif
