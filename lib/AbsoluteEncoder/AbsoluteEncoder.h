#include <WPILib.h>
#include <AnalogInput.h>

#pragma once

class AbsoluteEncoder : public AnalogInput
{
public:
    AbsoluteEncoder(int channel);
    ~AbsoluteEncoder();
	double GetVoltageRound();
	double PIDGet();
};