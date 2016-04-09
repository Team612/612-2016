#include "AlignToShoot.h"
#include <Commands/Autonomous/Sequences/AutoAlign.h>
#include <Commands/Autonomous/Sequences/VerticalAlign.h>
#include "SetShooterAngle.h"

AlignToShoot::AlignToShoot()
{
	AddSequential(new AutoAlign(HorizontalFind::RIGHT));
	AddSequential(new VerticalAlign());
}
