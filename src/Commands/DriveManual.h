#ifndef DriveManual_H
#define DriveManual_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveManual: public CommandBase
{
public:
	DriveManual();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
