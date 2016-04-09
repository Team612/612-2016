#pragma once

#include <Commands/Subsystem.h>
#include "Robot.h"

class DriveJoystick: public Command
{
public:
	DriveJoystick();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float XDEADZONE = 0.1; //constant
	float JDEADZONE = 0.1; //also constant
	//these may be adjusted

	float leftPos; //also joystickY
	float rightPos; //also joystickTwist
};


