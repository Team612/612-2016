#ifndef FireShooter_H
#define FireShooter_H

#include "Commands/Command.h"
#include "WPILib.h"

class ShooterControl: public Command
{
private:
    bool firing;
    bool fired;
    const float TOLERANCE = 10E-1;
    void Fire();
    void Intake();
    void Stop();
public:
	ShooterControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
