#ifndef WheelSet_H
#define WheelSet_H

#include "../CommandBase.h"
#include "WPILib.h"

class WheelSet: public CommandBase
{
public:
	WheelSet();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
