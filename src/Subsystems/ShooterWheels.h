#ifndef ShooterWheels_H
#define ShooterWheels_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterWheels: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterWheels();
	void InitDefaultCommand();
};

#endif
