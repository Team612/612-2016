#include "Autonomous.h"

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

	// Built-in antivirus to protect against terrible code from Ben
	/*int RemoveHackers(short germx)	//set germx to the number of bacteria you want killed (Default 512)
	{
		char *disinfectant;
		char *
		disinfectant = (char *)malloc(germx);
	}*/

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
	AddSequential(new SetShooter(1));
	//2 seconds
	AddSequential(new DelayCommand(1.5f));
	AddSequential(new Shoot(true));
	//AddSequential(new DelayCommand(0.5));
	//AddSequential(new Shoot(false)); // This should automatically happen
	AddSequential(new SetShooter(0));
	std::printf("Info: End auto!\n");
	//leaves 5ish seconds to align horizontally and vertically
}
