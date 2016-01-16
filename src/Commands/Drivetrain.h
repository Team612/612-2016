#ifndef Drivetrain_H
#define Drivetrain_H

#include "../CommandBase.h"
#include "WPILib.h"

class Drivetrain: public CommandBase
{
public:
	Drivetrain();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
