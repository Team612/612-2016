#pragma once
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
