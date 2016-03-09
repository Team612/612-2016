#ifndef FIND_TARGET_H
#define FIND_TARGET_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "../Robot.h"


class FindTarget: public Command
{
public:
	enum Direction {LEFT, RIGHT};

	FindTarget(Direction d);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int dir;

};

#endif
