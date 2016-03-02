#ifndef CalcAngle_H
#define CalcAngle_H


#include "WPILib.h"

class CalcAngle: public Command
{
public:
	CalcAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
