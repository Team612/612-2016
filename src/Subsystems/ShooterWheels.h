#ifndef ShooterWheels_H
#define ShooterWheels_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
class ShooterWheels: public Subsystem
{
private:

	std::shared_ptr<CANTalon>CANTalon1;
	std::shared_ptr<CANTalon>CANTalon2;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterWheels();
	float getLeftWheelSpeed();
	float getRightWheelSpeed();
	void setWheelSpeed(float speed);

	void InitDefaultCommand();
};

#endif
