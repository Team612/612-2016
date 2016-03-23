#ifndef ArmJoystick_H
#define ArmJoystick_H

#include "Commands/Command.h"
#include "WPILib.h"

class ArmJoystick: public Command
{
private:
	const float THRESHOLD = 0.01f;
public:
	ArmJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
