/*
 * Shoot.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: user
 */

#include <Commands/Shooter/Shoot.h>

Shoot::Shoot(bool push)
{
	Requires(Robot::pneumatics.get());
	this->solenoid = RobotMap::shooterSolenoid.get();
	this->push = push;
	this->iterations = 0;
}

void Shoot::Initialize()
{
	solenoid->Set(push);
}

void Shoot::Execute()
{
	iterations++; // This is called 60 times per second
}

bool Shoot::IsFinished()
{
	return iterations > (int)(SECONDS_TO_WAIT * 60);
}

void Shoot::End()
{
}

void Shoot::Interrupted()
{
}
