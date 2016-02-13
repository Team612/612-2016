#ifndef WheelSet_H
#define WheelSet_H

#include "Commands/Command.h"
#include "WPILib.h"

class WheelSet: public Command
{
private:
	float speed;
	bool isDone = false;
	const float THRESHHOLD = 100.0f;
public:
	WheelSet(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
