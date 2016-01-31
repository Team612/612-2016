#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	std::shared_ptr<NetworkTable> table;

public:
	Vision();
	void InitDefaultCommand();
	void PullValues();
};

#endif
