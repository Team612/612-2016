#pragma once

#include <Commands/CommandGroup.h>
#include "Sequences/AutoAlign.h"
#include "Sequences/VerticalAlign.h"
#include "Sequences/SimpleAutonomous.h"

#include <Commands/Shooter/SetShooter.h>
#include <WPILib.h>
#include <Commands/Shooter/Shoot.h>
#include <Commands/Shooter/SetShooterAngle.h>

class Autonomous: public CommandGroup
{
public:
	Autonomous();
};
