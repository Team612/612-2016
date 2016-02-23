#ifndef AutoWheels_H
#define AutoWheels_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoWheels: public Command
{
public:
	AutoWheels();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	const float TOLERANCE = 0.1f;
};

#endif
