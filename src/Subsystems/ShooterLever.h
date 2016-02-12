#ifndef ShooterLever_H
#define ShooterLever_H

#include "Commands/Subsystem.h"
#include "Commands/AutoServo.h"
#include "WPILib.h"
#include "AnalogInput.h"
#include <cmath>

class ShooterLever: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	std::shared_ptr<Servo> LeverServo1;
	//std::shared_ptr<AnalogInput> balldetector;
	ShooterLever();
	void InitDefaultCommand();
    void SetServoPosition(float position);
    void SetServoAngle(float angle);
    float getIRInInches(std::shared_ptr<AnalogInput> ir);
    float GetServoPosition();
    float GetServoAngle();
    std::shared_ptr<Servo> getLeverServo1();
    std::shared_ptr<AnalogInput> getBallDetector();
};

#endif
