#ifndef ARMMOVE_H
#define ARMMOVE_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ArmMove: public Command
{
private:
	std::shared_ptr<Joystick> driverJoystick;

public:
	ArmMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	short int myAxis = 02; //axis to use with Xbox control, set to left Y axis here
	bool isXbox;
	float myVal;
	float DEADZONE = 0.1;
};

#endif
