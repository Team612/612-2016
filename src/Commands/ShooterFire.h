#ifndef ShooterFire_H
#define ShooterFire_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterFire: public Command
{
public:
	ShooterFire();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
