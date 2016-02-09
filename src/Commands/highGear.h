#ifndef highGear_H
#define highGear_H

#include "../CommandBase.h"
#include "WPILib.h"

class highGear: public CommandBase
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
