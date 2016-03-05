#ifndef ShooterRotation_H
#define ShooterRotation_H
//#define DEBUG

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "CANSpeedController.h"
#include "CANTalon.h"

class ShooterRotation : public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double PositionToVolts(double angle);

	std::shared_ptr<CANTalon> RotateMotor;

	double pos = HOME_POS;

	double AngleToVolts(double angle);

public:
	const double MAX_ANGLE = 288; //full forwards
	const double MIN_ANGLE = 79.2; //full inwards

	const double MIN_VOLTS = 1.17f;
	const double MAX_VOLTS = 4.0f;

	const double HOME_POS = 0; //full inwards
	const double INTAKE_POS = 208.8; //full forwards

	ShooterRotation();
	void SetSpeed(float speed);
	void SetAngle(double pos); //in degrees range 0-208.8
	void IncrementAngle(double inc);
	void ShooterHome();
	float GetSpeed();
	void SetMode(CANTalon::ControlMode mode);
	void SetPIDEnabled(bool enabled);
	void SetPID(double p, double i, double d);

	double ReturnPIDInput();
	void UsePIDOutput(double output);

	void InitDefaultCommand();

};

#endif
