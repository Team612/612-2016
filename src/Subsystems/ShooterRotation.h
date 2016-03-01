#ifndef ShooterRotation_H
#define ShooterRotation_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANSpeedController.h"
#include "CANTalon.h"

class ShooterRotation : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double PositionToVolts(double angle);

	std::shared_ptr<CANTalon> RotateMotor;
	const double HOME_POS = 1.1f;
	double pos = HOME_POS;

	/*const double MAX_ANGLE = 270;
	const double MIN_ANGLE = 0;*/

	const double MAX_VOLTS = 1.1f;
	const double MIN_VOLTS = 4.0f;

public:
	ShooterRotation();
	void SetSpeed(float speed);
	void SetPosition(double pos); //in degrees
	void IncrementAngle(double inc);
	void ShooterHome();
	float GetSpeed();
	void SetMode(CANTalon::ControlMode mode);

	/*double ReturnPIDInput();
	void UsePIDOutput(double output);*/

	void InitDefaultCommand();
};

#endif
