#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class SetShooter: public Command
{
	private:
	float speed;
public:
	SetShooter(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
