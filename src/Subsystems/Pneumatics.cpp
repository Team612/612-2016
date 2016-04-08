#include <Subsystems/Pneumatics.h>
#include <Commands/Shooter/Shoot.h>

Pneumatics::Pneumatics() : Subsystem("Pneumatics")
{
}

void Pneumatics::InitDefaultCommand()
{
	//SetDefaultCommand(new Shoot(false));
}
