#ifndef ShooterLever_H
#define ShooterLever_H

#include <cmath>
#include <WPILib.h>
#include <AnalogInput.h>

enum ShooterActuatorPosition
{
   // Clamp,
    Neutral,
    Push
};

class ShooterActuator: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

    //const float CLAMP_SPEED = -1.0f;
	/*
	 * The motor should never move backwards
	 */
    const float NEUTRAL_SPEED = 0.0f;
    const float PUSH_SPEED = 0.75f;
    float storedposition;
public:
	std::shared_ptr<CANTalon> actuator;
	std::shared_ptr<AnalogInput> IR;
	std::shared_ptr<Relay> spike;

	bool CanShoot;

	//std::shared_ptr<AnalogInput> balldetector;
	ShooterActuator();
	void InitDefaultCommand();
    void SetPosition(ShooterActuatorPosition position, bool sol);
    void SetSpeed(float position);
    void SetAngle(float angle);
    void SetNeutral();
    //void SetClamp();
    void SetPush();
    float getIRInInches();
    float GetSpeed();
    bool AtSetPosition();
    //float GetAngle();
    //Servo* getLeverServo1();
    //AnalogInput* getBallDetector();
};

#endif
