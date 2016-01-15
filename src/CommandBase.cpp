#include "CommandBase.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	navx = NavX(SPI::Port::kMXP);
}
