#include "FireShooter.h"
#include "../Robot.h"

FireShooter::FireShooter()
{
	AddSequential(new WheelSet(this->MAXSPEED));
	AddSequential(new ServoPush());
}
