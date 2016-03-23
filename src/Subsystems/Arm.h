#ifndef Arm_H
#define Arm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Arm: public Subsystem
{
private:
	std::shared_ptr<CANTalon> rotateMotor;
public:
	Arm();
	void InitDefaultCommand();
	void SetSpeed(float speed);
};

#endif
