#include "Autonomous.h"
#include "../Shooter/SpinUp.h"
#include "../Shooter/Shoot.h"
#include "../Shooter/StopShooter.h"
#include "../Shooter/SetShooterAngle.h"

class DelayCommand : public Command
{
//Ben's jankness
private:
	float time;
public:
	DelayCommand(float time)
	{
		this->time = time;
	}

	void Initialize() { SetTimeout(time); };
	void Execute() { };

	bool IsFinished()
	{
		return IsTimedOut();
	}

	void End() { };
	void Interrupted() { };
};

Autonomous::Autonomous()
{
	//8 seconds
	AddSequential(new SimpleAutonomous(8, 0.6));
	AddParallel(new AutoAlign(FindTarget::RIGHT));
	AddParallel(new SetShooterAngle());
	AddSequential(new SpinUp());
	//2 seconds
	AddSequential(new DelayCommand(1.5f));
	AddSequential(new Shoot(true));
	AddSequential(new DelayCommand(0.5));
	AddSequential(new Shoot(false));
	AddSequential(new StopShooter());
	std::printf("Info: End auto!\n");
	//leaves 5ish seconds to align horizontally and vertically
}
