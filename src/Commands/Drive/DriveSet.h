#pragma once

#include <Commands/Subsystem.h>
#include <Robot.h>

class DriveSet: public Command
{
public:
	DriveSet(float val1, float val2);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float outputPower;
	float curveSharpness;
};

