#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shifter: public Subsystem
{
public:
	std::shared_ptr<Servo> shifterL;
	std::shared_ptr<Servo> shifterR;
	Shifter();
	void InitDefaultCommand();
	void Set(float shiftPower);
	float Get();

	static constexpr float LOW = 1.0f;
	static constexpr float HIGH = 0.0f;
};


