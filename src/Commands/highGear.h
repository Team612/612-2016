#ifndef highGear_H
#define highGear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class highGear: public Command
{
public:
	highGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
