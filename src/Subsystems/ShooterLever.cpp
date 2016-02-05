#include "ShooterLever.h"
#include "../RobotMap.h"

ShooterLever::ShooterLever() :
		Subsystem("ShooterLever")
{
	LeverServo1 = RobotMap::shooterLeverServo1;
}

void ShooterLever::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
