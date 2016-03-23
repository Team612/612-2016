#ifndef ShooterRotation_H
#define ShooterRotation_H
//#define DEBUG

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <CANTalon.h>
#include <AbsoluteEncoder/AbsoluteEncoder.h>
#include <PIDControl/PIDControl.h>

class ShooterRotation : public Subsystem
{
private:
	// Hardware
	std::shared_ptr<CANTalon> motor;
	PIDControl* pid;
	AbsoluteEncoder* absEncoder;
	
	// PID Constants
	float kP = 1.2f;
	float kI = 0.025f;
	float kD = 0.5f;
	float gain_switch = 0.6f; // Error value (Volts) at which the controller switches between PID and P control.
	
	// Common setpoints, tied to buttons.
	const float HOME_SETPOINT = 0;
	const float INTAKE_SETPOINT = 3;
	const float LOGOAL_SETPOINT = 0;
	const float HIGOAL_SETPOINT = 0;
	
	const float V_OVER_A = (5.0 / 360.0); // Constant to convert between voltage and angle.
	const float BIAS = 0; // Difference between home position and parallel with floor.
	
	float ConvertAngleToAbsolute(float angle)
	{
		return (angle * V_OVER_A) + HOME_SETPOINT + BIAS;
	}
	
	void SetSetpoint(float set);

public:
	//const double MAX_ANGLE = 288; //full forwards
	//const double MIN_ANGLE = 79.2; //full inwards

	//const double MIN_VOLTS = 1.17f;
	//const double MAX_VOLTS = 4.0f;

	//const double HOME_POS = 0; //full inwards
	//const double INTAKE_POS = 208.8; //full forwards

	ShooterRotation();
	/*void SetSpeed(float speed);
	void SetAngle(double pos); //in degrees range 0-208.8
	void IncrementAngle(double inc);
	void ShooterHome();
	float GetSpeed();
	void SetMode(CANTalon::ControlMode mode);
	void SetPIDEnabled(bool enabled);
	void SetPID(double p, double i, double d);*/
	/*
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	*/
	
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
};

#endif
