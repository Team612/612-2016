#ifndef LowGear_H
#define LowGear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LowGear: public Command
{
public:
	LowGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
