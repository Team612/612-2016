#ifndef FireShooter_H
#define FireShooter_H

#include "Commands/Command.h"
#include "WPILib.h"

class FireShooter: public Command
{
private:
    bool fired = false;
public:
	FireShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
