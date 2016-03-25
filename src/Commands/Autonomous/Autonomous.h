#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "Commands/CommandGroup.h"
#include "Robot.h"
#include <Timer.h>

class Autonomous: public CommandGroup
{
private:
	float time;
	float speed;

	double start_time;
	double current_time;

	Timer* autoTime;
public:
	Autonomous(float time, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
