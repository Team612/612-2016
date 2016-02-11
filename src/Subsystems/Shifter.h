#ifndef Shifter_H
#define Shifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Shifter: public Subsystem
{
private:

	std::shared_ptr<Servo> ShifterServo1;
	std::shared_ptr<Servo> ShifterServo2;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Shifter();
	void InitDefaultCommand();
	void SetShifter(float shiftPower);
	float GetShifter();
};

#endif
