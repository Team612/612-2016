#ifndef NAVX_H
#define NAVX_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Libraries/NavX/include/AHRS.h"

class NavX: public Subsystem, protected AHRS //protected so no calls to AHRS except through NavX
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	NavX(SPI::Port portId);
	void InitDefaultCommand();
};

#endif
