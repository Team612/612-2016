#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class ShooterManualControl: public Command
{
private:
    const float TOLERANCE = 0.1f;
    void Fire();
    void Intake();
    void Stop();
public:
	ShooterManualControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

