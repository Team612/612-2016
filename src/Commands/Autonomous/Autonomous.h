#pragma once

#include "Commands/CommandGroup.h"
#include "Sequences/AutoAlign.h"
#include "Sequences/SimpleAutonomous.h"
#include "../Shooter/SpinUp.h"
#include "../Shooter/StopShooter.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
public:
	Autonomous();
};
