#ifndef ServoNeutral_H
#define ServoNeutral_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ServoNeutral: public Command
{
public:
	ServoNeutral();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
};

#endif
