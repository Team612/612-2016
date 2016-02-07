#ifndef ShooterRotation_H
#define ShooterRotation_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterRotation: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterRotation();
	void InitDefaultCommand();
};

#endif
