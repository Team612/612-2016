#ifndef ShooterLever_H
#define ShooterLever_H

#include <cmath>
#include "WPILib.h"
#include "AnalogInput.h"
#include "Commands/Subsystem.h"
#include "Commands/AutoServo.h"

class ShooterLever: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	std::shared_ptr<Servo> LeverServo1;
	std::shared_ptr<AnalogInput> irsensor;

	//std::shared_ptr<AnalogInput> balldetector;
	ShooterLever();
	void InitDefaultCommand();
    void SetServoPosition(float position);
    void SetServoAngle(float angle);
    float getIRInInches();
    float GetServoPosition();
    float GetServoAngle();
    //Servo* getLeverServo1();
    //AnalogInput* getBallDetector();
};

#endif
