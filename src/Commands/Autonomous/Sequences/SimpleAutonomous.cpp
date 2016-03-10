#include "SimpleAutonomous.h"
#include "../AutoDrive.h"

SimpleAutonomous::SimpleAutonomous()
{
	d = DEFAULT_DURATION;
	s = DEFAULT_SPEED;

	AddSequential(new AutoDrive(d, s));
}

SimpleAutonomous::SimpleAutonomous(int d, float s)
{
	this->d = d;
	this->s = s;

	AddSequential(new AutoDrive(d, s));
}
