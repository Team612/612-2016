#ifndef PIDCOUNTER_H
#define PIDCOUNTER_H

#include <Counter.h>
#include <PIDSource.h>

class PIDEdgeCounter : public Counter, public PIDSource 
{
public:
    PIDEdgeCounter(int channel);
    double PIDGet();
};

#endif // PIDCOUNTER_H
