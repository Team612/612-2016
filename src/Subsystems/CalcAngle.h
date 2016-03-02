#ifndef CalcAngle_H
#define CalcAngle_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#include <cmath> //for atan()

class CalcAngle: public Subsystem
{
private:
	const int projectile_speed = 0; //TODO find actual value (m/s)
	const int height_of_goal = 2.3114; //TODO find this in the manual (m)
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
