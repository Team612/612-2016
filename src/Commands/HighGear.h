#ifndef HighGear_H
#define HighGear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class HighGear: public Command
{
public:
	HighGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

