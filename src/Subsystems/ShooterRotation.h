#ifndef ShooterRotation_H
#define ShooterRotation_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <CANSpeedController.h>

class ShooterRotation: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> RotateMotor;
public:
	ShooterRotation();
	void SetShooter(float position);
	float GetShooter();
	void SetShooterMode(CANTalon::ControlMode mode);
	void InitDefaultCommand();
};

#endif
