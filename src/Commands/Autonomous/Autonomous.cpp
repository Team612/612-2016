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

	void Initialize() {}
	void Execute() {}
	void Interrupted() {}
	void End() {}
};

Autonomous::Autonomous()
{
	AddSequential(new SimpleAutonomous(8.0f, 0.8f));
	AddSequential(new AutoAlign(HorizontalFind::RIGHT));
	AddSequential(new SpinUp());
	AddSequential(new Shoot(true));
	AddSequential(new StopShooter());
}
