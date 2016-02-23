#ifndef DriveDistance_H
#define DriveDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDistance: public CommandBase
{
public:
	DriveDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
