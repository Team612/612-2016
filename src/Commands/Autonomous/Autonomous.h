#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
#include "Robot.h"
#include <Timer.h>

class Autonomous: public CommandGroup
{
private:
	float time;
	float speedL;
	float speedR;
	float original_speed;

	double start_time;
	double current_time;

	Timer* autoTime;

	const int THRESHOLD         = 5; //degrees
	const int MAX_YAW_ERROR     = 10; //degrees
	const float INCREMENT       = 1.05;
public:
	Autonomous(float time, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
