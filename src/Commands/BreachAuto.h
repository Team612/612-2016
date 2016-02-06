#ifndef BreachAuto_H
#define BreachAuto_H

#include "Commands/Command.h"
#include "WPILib.h"

class BreachAuto: public Command
{
public:
	BreachAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
