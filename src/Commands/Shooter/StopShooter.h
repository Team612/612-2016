#ifndef StopShooter_H
#define StopShooter_H

#include "Commands/Command.h"
#include "WPILib.h"

class StopShooter: public Command
{
public:
	StopShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
