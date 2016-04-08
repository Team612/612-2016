#pragma once

#include "Commands/CommandGroup.h"
#include "Robot.h"
#include <Timer.h>

class SimpleAutonomous: public CommandGroup
{
private:
	float time;
	float speed;
	float original_speed;
	float rotation = 0;

	double start_time;
	double current_time;

	Timer* autoTime;

	const int THRESHOLD                  = 5; //degrees
	const int MAX_YAW_ERROR              = 10; //degrees
	const float TIMES_INCREMENT          = 1.005;
	const float ADD_INCREMENT            = 0.005;
public:
	SimpleAutonomous(float time, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
