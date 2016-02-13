#ifndef InvertControls_H
#define InvertControls_H

#include "WPILib.h"
#include "Robot.h"

class InvertControls: public Command
{
private:
	std::shared_ptr<Joystick> driverJoy;

public:
	InvertControls();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
