#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoDrive: public Command
{
private:
	std::unique_ptr<Timer> time;
	int duration;
	float speed;
public:
	AutoDrive(int duration, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
