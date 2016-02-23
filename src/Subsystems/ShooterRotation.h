#ifndef ShooterRotation_H
#define ShooterRotation_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANSpeedController.h"
#include "CANTalon.h"

class ShooterRotation: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> RotateMotor;
	const float HOME_POS = 0.0;
public:
	ShooterRotation();
	void SetSpeed(float speed);
	void ShooterHome();
	float GetSpeed();
	void SetMode(CANTalon::ControlMode mode);
	void InitDefaultCommand();
};

#endif
