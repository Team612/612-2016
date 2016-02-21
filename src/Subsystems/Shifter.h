#ifndef Shifter_H
#define Shifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	std::shared_ptr<Servo> ShifterServo1;
	std::shared_ptr<Servo> ShifterServo2;
	Shifter();
	void InitDefaultCommand();
	void SetShifter(float shiftPower);
	float GetShifter();

	static constexpr float LOW = 0.0f;
	static constexpr float HIGH = 1.0f;
};

#endif
