#ifndef CalcAngle_H
#define CalcAngle_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include <cmath> //for atan()

class CalcAngle: public Subsystem
{
private:
	double projectile_speed; //TODO find actual value (m/s)
	const double height_of_goal = 2.3114;
	double wheel_rpm = 0; //TODO find
	double wheel_rps = 0;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double angle;
	double test;
public:
	CalcAngle();
	void InitDefaultCommand();
	double getAngleToFireAt(int distance_to_target);
};

#endif
