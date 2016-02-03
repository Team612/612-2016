#ifndef ShooterLever_H
#define ShooterLever_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterLever: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<Servo> LeverServo1;
public:
	ShooterLever();
	void InitDefaultCommand();
        void SetServoPosition(float position);
        void SetServoAngle(float angle);
        float GetServoPosition();
        float GetServoAngle();
};

#endif
