#ifndef DriveDistance_H
#define DriveDistance_H

#include "Commands/PIDCommand.h"
#include "WPILib.h"

class DriveDistance: public PIDCommand
{
public:
	DriveDistance(float end_distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	double ReturnPIDInput();
	void UsePIDOutput(double output);

private:
	float end_distance;
	const float STARTING_DISTANCE = 0.0f;
	const float SPEED             = 0.7f;
};

#endif
