#include "Fire.h"

#include "SpinUp.h"
#include "FireShooter.h"
#include "StopShooter.h"

Fire::Fire()
{
	AddSequential(new SpinUp());
	Wait(0.5);
	AddSequential(new FireShooter(ShooterActuatorPosition::Push));
	Wait(1.0);
	AddSequential(new StopShooter());
}
