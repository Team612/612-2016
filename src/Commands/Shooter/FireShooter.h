#ifndef FIRESHOOTER_H
#define FIRESHOOTER_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include "Robot.h"

class FireShooter: public Command
{
public:
	FireShooter(ShooterActuatorPosition position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	ShooterActuatorPosition position;
	int count = 0;
};

#endif
