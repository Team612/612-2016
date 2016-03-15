#include "Fire.h"

#include "SpinUp.h"
#include "FireShooter.h"
#include "StopShooter.h"

Fire::Fire()
{
	AddSequential(new SpinUp());
	Wait(0.5);
	AddSequential(new FireShooter(ShooterServoPosition::Push));
	Wait(1.0);
	AddSequential(new StopShooter());
}
