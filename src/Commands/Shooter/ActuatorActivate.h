#ifndef ActuatorActivate_H
#define ActuatorActivate_H

#include "Commands/Command.h"
#include "WPILib.h"

class ActuatorActivate: public Command
{
public:
	ActuatorActivate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
