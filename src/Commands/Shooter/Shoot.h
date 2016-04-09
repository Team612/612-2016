#pragma once

#include <Commands/Command.h>
#include <Robot.h>
#include <Solenoid.h>

class Shoot: public Command {
private:
	bool push;
	DoubleSolenoid* solenoid;
	int iterations;
	const float SECONDS_TO_WAIT = .5;

public:
	Shoot(bool push, float timeout = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

