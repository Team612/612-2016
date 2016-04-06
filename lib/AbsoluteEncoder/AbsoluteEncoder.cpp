#include "AbsoluteEncoder.h"

AbsoluteEncoder::AbsoluteEncoder(int channel) : AnalogInput(channel) {}

AbsoluteEncoder::~AbsoluteEncoder() {}

double AbsoluteEncoder::GetVoltageRound()
{
	return round(this->AnalogInput::GetVoltage() * 1000) / 1000.0;
}

double AbsoluteEncoder::PIDGet()
{
	return round(this->AnalogInput::PIDGet() * 1000) / 1000.0;
}
