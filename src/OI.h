#pragma once

#include "WPILib.h"

class OI
{
private:
	std::shared_ptr<Joystick> gunner;
	//std::shared_ptr<JoystickButton> fireButton; //when pressed
	std::shared_ptr<JoystickButton> servoPush; //while held
	std::shared_ptr<JoystickButton> servoClamp; //while held

	std::shared_ptr<Joystick> driver;
	std::shared_ptr<JoystickButton> resetButton; //wot?
	std::shared_ptr<JoystickButton> reverseControls; //while held
	std::shared_ptr<JoystickButton> lowGear; //when pressed
	std::shared_ptr<JoystickButton> highGear; //when pressed

public:
	OI();

	std::shared_ptr<Joystick> getDriver();
	std::shared_ptr<Joystick> getGunner();
};

