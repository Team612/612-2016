#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class SetShooter: public Command
{
	private:
	float speed;
public:
	SetShooter(float speed, float timout = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
