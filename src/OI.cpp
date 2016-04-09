#include <Commands/Shooter/ShooterControl.h>
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
	align.get()->WhileHeld(new AlignToShoot());

	//shooterHome.reset(new JoystickButton(gunner.get(), 3)); //x button
	//shooterHome.get()->WhenPressed(new SetShooterAngle(0));

	//shooterIntake.reset(new JoystickButton(gunner.get(), 2)); //b button
	//shooterIntake.get()->WhenPressed(new SetShooterAngle(186));

	//DRIVER
	driver.reset(new Joystick(0));

	//resetButton.reset(new JoystickButton(driver.get(), 2));
	//resetButton->WhenPressed(new DriveJoystick());

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
