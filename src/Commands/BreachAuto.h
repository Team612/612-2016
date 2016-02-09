#ifndef BreachAuto_H
#define BreachAuto_H

#include "Commands/Command.h"
#include "WPILib.h"

#include "../Robot.h"

class BreachAuto: public Command
{
private:
	Robot::Defense defense;
public:
	BreachAuto(Robot::Defense defense);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
