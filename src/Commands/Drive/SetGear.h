#ifndef SET_GEAR_H
#define SET_GEAR_H

#include "WPILib.h"
#include "Robot.h"

class SetGear: public Command
{
public:
	SetGear(float gear); //Use Shifter::HIGH and Shifter::LOW
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float gear;
};

#endif
