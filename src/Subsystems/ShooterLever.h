#ifndef ShooterLever_H
#define ShooterLever_H

#include <cmath>
#include <WPILib.h>
#include <AnalogInput.h>
#include "Commands/Autonomous/AutoServo.h"

enum ShooterServoPosition
{
    Clamp,
    Neutral,
    Push
};

class ShooterLever: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
    const float CLAMP_POS = 1.0f;
    const float NEUTRAL_POS = 0.5f;
    const float PUSH_POS = 0.0f;
    float storedposition;
public:
	std::shared_ptr<Servo> LeverServo;
	std::shared_ptr<AnalogInput> irsensor;

	bool CanShoot;

	//std::shared_ptr<AnalogInput> balldetector;
	ShooterLever();
	void InitDefaultCommand();
    void SetPosition(ShooterServoPosition position);
    void SetPosition(float position);
    void SetAngle(float angle);
    void SetNeutral();
    void SetClamp();
    void SetPush();
    float getIRInInches();
    float GetPosition();
    bool AtSetPosition();
    //float GetAngle();
    //Servo* getLeverServo1();
    //AnalogInput* getBallDetector();
};

#endif
