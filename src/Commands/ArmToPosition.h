#ifndef ArmToPosition_H
#define ArmToPosition_H

#include "Commands/Command.h"
#include "WPILib.h"

class ArmToPosition: public Command
{
public:
	ArmToPosition(float position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	const float THRESHOLD    = 0.3f; //units
	const float CLOSE_ENOUGH = 0.025f; //units
	const float SCALE        = 1.5f;

private:
	float position;
	float power;
};

#endif
