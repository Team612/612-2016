#include "AbsoluteEncoder.h"

AbsoluteEncoder::AbsoluteEncoder(int channel) : AnalogInput(channel) {}

AbsoluteEncoder::~AbsoluteEncoder() {}

double AbsoluteEncoder::GetVoltageRound()
{
	return round(this->AnalogInput::GetVoltage() * 100) / 100.0;
}

double AbsoluteEncoder::PIDGet()
{
	return round(this->AnalogInput::PIDGet() * 100) / 100.0;
}
