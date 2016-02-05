#ifndef ServoNeutral_H
#define ServoNeutral_H

#include "WPILib.h"
#include "Subsystems/ShooterLever.h"

class ServoNeutral: public CommandBase
{
public:
	ServoNeutral();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Servo* temp;
};

#endif
