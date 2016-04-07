#include "AlignToShoot.h"
#include <Commands/Autonomous/Sequences/AutoAlign.h>
#include <Commands/Autonomous/Sequences/VerticalAlign.h>
#include "SetShooterAngle.h"

AlignToShoot::AlignToShoot()
{
	AddParallel(new AutoAlign(HorizontalFind::RIGHT));
	AddParallel(new VerticalAlign());
}
