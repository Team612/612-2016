#ifndef AutoServo_H
#define AutoServo_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoServo: public Command
{
public:
	AutoServo();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
