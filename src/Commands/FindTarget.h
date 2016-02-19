#ifndef FIND_TARGET_H
#define FIND_TARGET_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Robot.h"


class FindTarget: public CommandBase
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
