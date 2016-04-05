//Chantilly612 can into spelling please!

#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class ShooterManuelControl: public Command
{
private:
    const float TOLERANCE = 0.1f;
    void Fire();
    void Intake();
    void Stop();
public:
	ShooterManuelControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

