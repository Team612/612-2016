#ifndef ActuateLimit_H
#define ActuateLimit_H

#include "Commands/Command.h"
#include "WPILib.h"

class ActuateLimit: public Command
{
private:
	bool finished = false;
	Timer* failsafe;
	double start_time;
	//std::chrono::high_resolution_clock::time_point start_time;
public:
	ActuateLimit();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
