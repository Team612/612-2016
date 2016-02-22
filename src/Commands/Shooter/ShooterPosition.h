#ifndef ShooterPosition_H
#define ShooterPosition_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Robot.h"
class ShooterPosition: public Command
{
private:
	float shooterthing;
public:
	ShooterPosition(float shootpos);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

