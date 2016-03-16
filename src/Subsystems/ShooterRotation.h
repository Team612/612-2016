#ifndef ShooterRotation_H
#define ShooterRotation_H
//#define DEBUG

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <CANTalon.h>
#include <AbsoluteEncoder.h>

class ShooterRotation : public Subsystem
{
private:
	std::shared_ptr<CANTalon> motor;
	PIDController* pid;
	AbsoluteEncoder* absEncoder;
	float kP = .1;
	float kI = 0;
	float kD = 0;
	const float HOME_SETPOINT = 0;
	
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
	
	void Stop();
	
	void Enable();
	void Disable();
	
	void SmartDashboardOutput();
};

#endif
