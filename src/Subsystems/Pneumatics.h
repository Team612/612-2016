#pragma once

#include <Commands/Subsystem.h>

class Pneumatics: public Subsystem
{
public:
	Pneumatics();
	void InitDefaultCommand();
};
