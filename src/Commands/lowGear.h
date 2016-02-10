#ifndef lowGear_H
#define lowGear_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class lowGear: public Command
{
public:
	lowGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
