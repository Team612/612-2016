#ifndef ShooterFire_H
#define ShooterFire_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterFire: public CommandBase
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
