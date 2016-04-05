#include "AlignToShoot.h"
#include "../Autonomous/Sequences/AutoAlign.h"
#include "SetShooterAngle.h"

AlignToShoot::AlignToShoot()
{
	AddParallel(new AutoAlign(FindTarget::RIGHT));
	AddParallel(new SetShooterAngle());
}
