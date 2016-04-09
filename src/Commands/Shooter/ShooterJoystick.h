#pragma once
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Robot.h"
class ShooterJoystick: public Command
{
public:
	ShooterJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	const float TOLERANCE = 0.1;
};
