#ifndef ArmMove_H
#define ArmMove_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "Joystick.h"

#include "../Subsystems/Arm.h"
#include "../Robot.h"
#include "../RobotMap.h"

class ArmMove: public CommandBase
{
private:
	std::shared_ptr<Joystick> gj;
public:
	ArmMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
