#include "OI.h"
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/SetGear.h"
#include "Commands/Shooter/AlignToShoot.h"
#include "Commands/Shooter/SetShooterAngle.h"
#include <Commands/Shooter/Shoot.h>

OI::OI()
{
	//GUNNER
	gunner.reset(new Joystick(1));

	shoot.reset(new JoystickButton(gunner.get(), 1)); //a button
	shoot.get()->WhenPressed(new Shoot(true));
	shoot.get()->WhenReleased(new Shoot(false));

	align.reset(new JoystickButton(gunner.get(), 4)); //y button
	//align.get()->WhenPressed(new AlignToShoot());

	//DRIVER
	driver.reset(new Joystick(0));

	lowGear.reset(new JoystickButton(driver.get(), 5));
	lowGear->WhenPressed(new SetGear(Shifter::LOW));

	//highGear.reset(new JoystickButton(driver.get(), 6));
	//highGear->WhenPressed(new SetGear(Shifter::HIGH));
}

std::shared_ptr<Joystick> OI::getDriver()
{
	return driver;
}

std::shared_ptr<Joystick> OI::getGunner()
{
	return gunner;
}
