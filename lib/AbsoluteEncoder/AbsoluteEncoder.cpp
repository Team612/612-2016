#include "AbsoluteEncoder.h"

AbsoluteEncoder::AbsoluteEncoder(int channel) : AnalogInput(channel) {}

AbsoluteEncoder::~AbsoluteEncoder() {}

double AbsoluteEncoder::GetVoltageRound()
{
	return round(this->AnalogInput::GetVoltage() * 10) / 10.0;
}

double AbsoluteEncoder::PIDGet()
{
	return round(this->AnalogInput::PIDGet() * 10) / 10.0;
}