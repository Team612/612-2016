#ifndef SetServoPosition_H
#define SetServoPosition_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "Robot.h"


enum ShooterServoPosition
{
    Clamp,
    Neutral,
    Push
};

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
	float position;
};

#endif
