#ifndef RUMBLE_H
#define RUMBLE_H

#include "../CommandBase.h"
#include "../Robot.h"
#include "WPILib.h"

class Rumble: public CommandBase
{
public:
	Rumble(OI::Stick stick, OI::RumbleSide side, float intensity, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	OI::Stick stick;
	OI::RumbleSide side;
	float intensity;
};

#endif
