#include "PIDEdgeCounter.h"

PIDEdgeCounter::PIDEdgeCounter(int channel) : Counter(channel)
{
    this->SetUpSourceEdge(true, false);
}

double PIDEdgeCounter::PIDGet() 
{
    return 1.0 / GetPeriod();
}
