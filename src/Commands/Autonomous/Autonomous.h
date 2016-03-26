#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/CommandGroup.h"
#include "Sequences/AutoAlign.h"
#include "../Shooter/FireShooter.h"
#include "Sequences/SimpleAutonomous.h"
#include "../Shooter/SpinUp.h"
#include "../Shooter/StopShooter.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
public:
	Autonomous();
};

#endif
