#ifndef ARMMOVE_H
#define ARMMOVE_H

#include <Commands/Subsystem.h>
#include "Robot.h"

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

};

#endif
