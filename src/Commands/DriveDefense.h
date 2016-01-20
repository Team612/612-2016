#ifndef DriveDefense_H
#define DriveDefense_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveDefense: public CommandBase
{
public:
	DriveDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
