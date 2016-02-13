#include "FireShooter.h"
#include "WheelSet.h"
#include "ServoPush.h"

FireShooter::FireShooter()
{
	AddSequential(new WheelSet(this->MAXSPEED));
	AddSequential(new ServoPush());
}
