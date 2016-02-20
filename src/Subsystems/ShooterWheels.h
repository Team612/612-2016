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
    const float kP = 0.01;
    const float kI = 0.01;
    const float kD = 0.01;
    const float kTol = 2.0;  // tolerance
	std::shared_ptr<CANTalon>CANTalon1;
	std::shared_ptr<CANTalon>CANTalon2;
	PIDEdgeCounter* hallCounterLeft;
	PIDEdgeCounter* hallCounterRight;
	std::shared_ptr<PIDController> wheelControllerLeft;
	std::shared_ptr<PIDController> wheelControllerRight;
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
