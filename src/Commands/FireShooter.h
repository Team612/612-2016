#ifndef FireShooter_H
#define FireShooter_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class FireShooter: public CommandGroup
{
private:
	const float MAXSPEED = 1000.0f;
public:
	FireShooter();
};

#endif
