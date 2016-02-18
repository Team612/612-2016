#ifndef ArmJoystick_H
#define ArmJoystick_H
#include "Robot.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
class ArmJoystick: public Command
{
private:
	int dpadValue;
public:
	ArmJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
