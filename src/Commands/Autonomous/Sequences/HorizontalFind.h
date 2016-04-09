#ifndef FIND_TARGET_H
#define FIND_TARGET_H

#include "Commands/Command.h"
#include "WPILib.h"
#include "../../../Robot.h"


class HorizontalFind: public Command
{
public:
	enum Direction {LEFT, RIGHT};

	HorizontalFind(Direction d, float timeout = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	int dir;

};

#endif
