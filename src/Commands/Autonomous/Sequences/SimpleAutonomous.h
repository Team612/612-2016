#ifndef SimpleAutonomous_H
#define SimpleAutonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class SimpleAutonomous: public CommandGroup
{
private:
	const int DEFAULT_DURATION = 4;
	const float DEFAULT_SPEED  = 0.75f;

	int d; //duration
	float s; //speed
public:
	SimpleAutonomous();
	SimpleAutonomous(int d, float s);
};

#endif
