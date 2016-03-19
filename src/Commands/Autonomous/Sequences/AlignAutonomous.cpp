#include <Commands/Autonomous/Sequences/AlignAutonomous.h>
#include "../AutoDrive.h"
#include "../../AutoAlign.h"
#include "../../FindTarget.h"
#include "../../Shooter/SpinUp.h"
#include "../../Shooter/StopShooter.h"
#include "../../Shooter/FireShooter.h"
#include "../../Shooter/SetShooterAngle.h"

#include "../../../Subsystems/ShooterActuator.h"

AlignAutonomous::AlignAutonomous()
{
	d = DEFAULT_DURATION;
	s = DEFAULT_SPEED;

	AddSequential(new AutoDrive(d, s));
	AddSequential(new AutoAlign(FindTarget::RIGHT));
	AddSequential(new SetShooterAngle());
	AddSequential(new SpinUp());
	Wait(0.5);
	AddSequential(new FireShooter(ShooterServoPosition::Push));
	Wait(1.0);
	AddSequential(new StopShooter());
}

AlignAutonomous::AlignAutonomous(int d, float s)
{
	this->d = d;
	this->s = s;

	AddSequential(new AutoDrive(d, s));
	AddSequential(new AutoAlign(FindTarget::RIGHT));
	AddSequential(new SpinUp());
	Wait(0.5);
	AddSequential(new FireShooter(ShooterServoPosition::Push));
	Wait(1.0);
	AddSequential(new StopShooter());
}

