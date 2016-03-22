#ifndef ActuateLimit_H
#define ActuateLimit_H

#include "Commands/Command.h"
#include "WPILib.h"

class ActuateLimit: public Command
{
private:
	bool finished = false;
public:
	ActuateLimit();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
