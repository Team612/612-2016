#ifndef SpinUp_H
#define SpinUp_H

#include "Commands/Command.h"
#include "WPILib.h"

class SpinUp: public Command
{
public:
	SpinUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
