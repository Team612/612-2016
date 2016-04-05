#include "Autonomous.h"

class DelayCommand : public Command
{
public:
	DelayCommand(float time)
	{
		SetTimeout(time);
	}

	bool IsFinished()
	{
		return IsTimedOut();
	}
};

Autonomous::Autonomous()
{
	AddSequential(new SimpleAutonomous(7, 0.8));
	AddSequential(new AutoAlign(FindTarget::RIGHT));
	AddSequential(new SpinUp());
	Wait(1.0);
	AddSequential(new StopShooter());
}
