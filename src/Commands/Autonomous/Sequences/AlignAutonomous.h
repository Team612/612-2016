#ifndef AlignAutonomous_H
#define AlignAutonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AlignAutonomous: public CommandGroup
{
private:
	const int DEFAULT_DURATION = 4;
	const float DEFAULT_SPEED  = 0.75f;

	int d; //duration
	float s; //speed
public:
	AlignAutonomous();
	AlignAutonomous(int d, float sr);
};

#endif
