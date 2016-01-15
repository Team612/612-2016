#include "NavX.h"
#include "../RobotMap.h"

NavX::NavX(SPI::Port portId):Subsystem("NavX"):AHRS(portID)
{

}

void NavX::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

