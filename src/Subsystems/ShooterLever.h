#ifndef ShooterLever_H
#define ShooterLever_H

#include <cmath>
#include <WPILib.h>
#include <AnalogInput.h>
#include "Commands/Autonomous/AutoServo.h"

class ShooterLever: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
    const float CLAMP_POS = 0.0f;
    const float NEUTRAL_POS = 0.5f;
    const float PUSH_POS = 1.0f;
public:
	std::shared_ptr<Servo> LeverServo1;
	std::shared_ptr<AnalogInput> irsensor;

	//std::shared_ptr<AnalogInput> balldetector;
	ShooterLever();
	void InitDefaultCommand();
    void SetServoPosition(float position);
    void SetServoAngle(float angle);
    void SetNeutral();
    void SetClamp();
    void SetPush();
    float getIRInInches();
    float GetServoPosition();
    float GetServoAngle();
    //Servo* getLeverServo1();
    //AnalogInput* getBallDetector();
};

#endif
