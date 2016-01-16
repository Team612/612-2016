#ifndef DriveController_H
#define DriveController_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveController: public CommandBase
{
public:
	DriveController();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
