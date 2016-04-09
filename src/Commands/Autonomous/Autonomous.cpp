#include "Autonomous.h"
#include "Robot.h"

#include "Commands/WaitCommand.h"

#define SPY

Autonomous::Autonomous()
{
	#ifdef SPY
		AddSequential(new SetShooterAngle(55, 5));
		AddSequential(new SetShooter(1, 3.0f));
		AddSequential(new WaitCommand(2.0f));
		AddSequential(new Shoot(true, 0.5f));
		AddSequential(new Shoot(false));
		AddSequential(new SetShooter(0, 0.1f));
	#else
		AddSequential(new SimpleAutonomous(7, 0.6));
		AddSequential(new AutoAlign(HorizontalFind::RIGHT));
		AddSequential(new SetShooter(1, 3.0f));
		AddSequential(new WaitCommand(2.0f));
		AddSequential(new Shoot(true, 0.5f));
		AddSequential(new Shoot(false));
		AddSequential(new SetShooter(0, 0.1f));
	#endif
}
