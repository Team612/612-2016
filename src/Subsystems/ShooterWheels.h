#ifndef ShooterWheels_H
#define ShooterWheels_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"
#include "HallEffect/PIDEdgeCounter.h"
#include <PIDController.h>

class ShooterWheels: public Subsystem
{
private:
    // PID values
    const float kP = 0.1f;
    const float kI = 0.0f;
    const float kD = 0.0f;
    const float kTol = 0.05f;  // tolerance (within kTol * output)
	std::shared_ptr<CANTalon> CANTalonLeft;
//	std::shared_ptr<CANTalon> CANTalonRight;
	std::shared_ptr<PIDEdgeCounter> hallCounterLeft;
//	std::shared_ptr<PIDEdgeCounter> hallCounterRight;
	std::shared_ptr<PIDController> wheelControllerLeft;
//	std::shared_ptr<PIDController> wheelControllerRight;

	float leftLastErr = 999.9f;
	float rightLastErr = 999.9f;
	bool enabled = false;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterWheels();
	float GetLeftWheelSpeed();
//	float GetRightWheelSpeed();
	bool UpToSpeed();
	void SetWheelSpeed(float speed);
	void Disable();
	void Enable();
	void InitDefaultCommand();
};

#endif
