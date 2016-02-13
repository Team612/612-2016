#ifndef ShooterJoystick_H
#define ShooterJoystick_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterJoystick: public Command
{
public:
	ShooterJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
