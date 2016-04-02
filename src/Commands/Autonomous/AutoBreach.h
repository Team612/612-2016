#pragma once
#include "Commands/CommandGroup.h"
#include "Robot.h"
#include "WPILib.h"
#include <Timer.h>

class AutoBreach: public CommandGroup
{
private:
	Timer * time = new Timer();
public:
	AutoBreach(Robot::Defense defense);
};


