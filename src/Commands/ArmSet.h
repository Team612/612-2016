#ifndef ARMSET_H
#define ARMSET_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

#include <Timer.h>

class ArmSet: public Command
{
public:
	ArmSet(float val1, float val2);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float power;
	float time;

	Timer myTimer;
};

#endif
