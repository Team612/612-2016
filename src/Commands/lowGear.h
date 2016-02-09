#ifndef lowGear_H
#define lowGear_H

#include "../CommandBase.h"
#include "WPILib.h"

class lowGear: public CommandBase
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
