#pragma once
//#define DEBUG

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <TalonSRX.h>
#include <AbsoluteEncoder.h>
#include <PIDControl.h>
#include <cmath>

class ShooterRotation : public Subsystem
{
private:
	double PositionToVolts(double angle);

	std::shared_ptr<TalonSRX> RotateMotor;

	double AngleToVolts(double angle) {return (angle * V_OVER_A) + zerodegrees + BIAS;}

public:
	const double MAX_ANGLE = 190.0; //full forwards
	const double MIN_ANGLE = 0; //full inwards

	// Hardware
	std::shared_ptr<TalonSRX> motor;
	PIDControl* pid;
	AbsoluteEncoder* absEncoder;
	
	// PID Constants
	float kP = 20.0f;
	float kI = 0.0f;
	float kD = 0.0f;
	float gain_switch = 0.6f; // Error value (Volts) at which the controller switches between PID and P control.
	
	// Common setpoints, tied to buttons.
	const float zerodegrees = 1.704;
	const float oneeightydegrees = 2.095;
	
	const float INTAKE_ANGLE = 190;
	const float HOME_ANGLE = 0;
	const float LOGOAL_ANGLE = 180;
	const float HIGOAL_ANGLE = 55; //from spy corner

	const float V_OVER_A = (std::abs(oneeightydegrees - zerodegrees) / 180.0); // Constant to convert between voltage and angle.
	const float BIAS = 0; // Difference between home position and parallel with floor.
	
	void SetSetpoint(float set);

public:
	ShooterRotation();
	void SetAngle(double pos);
	
	void InitDefaultCommand();
	
	// Teleop Axis Control
	void Gun(float gunner_axis);
	
	// Button/Auto Control
	void HomePos();
	void ShootPos(float position);
	void IntakePos();
	
	void Stop();
	bool PIDEnabled() { return pid->IsEnabled(); }
	void PIDEnable(bool enabled);
	
	void SmartDashboardOutput();

	bool OnTarget();

	//PIDControl* getShooterPID();
};
