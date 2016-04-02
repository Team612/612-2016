#ifndef ActuateRelease_H
#define ActuateRelease_H

#include "Commands/Command.h"
#include "WPILib.h"

class ActuateRelease: public Command
{
public:
	ActuateRelease();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
