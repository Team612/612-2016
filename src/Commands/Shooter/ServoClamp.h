#ifndef ServoClamp_H
#define ServoClamp_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Robot.h"
class ServoClamp: public Command
{
public:
	ServoClamp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
