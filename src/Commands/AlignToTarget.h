#ifndef AlignToTarget_H
#define AlignToTarget_H

#include "../CommandBase.h"
#include "WPILib.h"

class AlignToTarget: public CommandBase
{
public:
	AlignToTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
