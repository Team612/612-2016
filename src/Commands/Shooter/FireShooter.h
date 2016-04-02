#pragma once
#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "Robot.h"

class FireShooter: public Command
{
private:
	bool solenoid;
public:
	FireShooter(ShooterActuatorPosition position, bool solenoid);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ShooterActuatorPosition position;
	int count = 0;
};

