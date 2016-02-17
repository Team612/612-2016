#ifndef ShooterJoystick_H
#define ShooterJoystick_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Robot.h"
class ShooterJoystick: public Command
{
private:
public:
	ShooterJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
