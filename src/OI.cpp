#include <Commands/Shooter/ShooterControl.h>
#include "OI.h"
#include "Commands/Drive/DriveJoystick.h"
#include "Commands/Drive/SetGear.h"
#include <Commands/Shooter/Shoot.h>

OI::OI()
{
	//GUNNER
	gunner.reset(new Joystick(1));

	shoot.reset(new JoystickButton(gunner.get(), 1));
	shoot->WhenPressed(new Shoot(true));

	//DRIVER
	driver.reset(new Joystick(0));

	//resetButton.reset(new JoystickButton(driver.get(), 2));
	//resetButton->WhenPressed(new DriveJoystick());

	lowGear.reset(new JoystickButton(driver.get(), 5));
	lowGear->WhenPressed(new SetGear(Shifter::LOW));

	highGear.reset(new JoystickButton(driver.get(), 6));
	// TODO: Change this back to Shifter::HIGH when shifters are fixed
	highGear->WhenPressed(new SetGear(Shifter::HIGH));
}

std::shared_ptr<Joystick> OI::getDriver()
{
	return driver;
}

std::shared_ptr<Joystick> OI::getGunner()
{
	return gunner;
}
