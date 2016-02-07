#ifndef ServoPush_H
#define ServoPush_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ServoPush: public Command
{
public:
	ServoPush();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
