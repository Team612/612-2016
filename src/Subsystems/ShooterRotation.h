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
	void SetShooter(float position);
	void ShooterHome();
	float GetShooter();
	void SetShooterMode(CANTalon::ControlMode mode);
	void InitDefaultCommand();
};

#endif
