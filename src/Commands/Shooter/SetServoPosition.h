#ifndef SetServoPosition_H
#define SetServoPosition_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "Robot.h"

class SetServoPosition: public Command
{
public:
	SetServoPosition(ShooterServoPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ShooterServoPosition position;
};

#endif
