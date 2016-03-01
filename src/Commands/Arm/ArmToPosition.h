#ifndef ArmToPosition_H
#define ArmToPosition_H

#include "Commands/Command.h"
#include "WPILib.h"

class ArmToPosition: public Command
{
private:
	float position;
public:
	ArmToPosition(float position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
