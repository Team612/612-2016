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
	iterations = 0;
	solenoid->Set(push ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
}

void Shoot::Execute()
{
	//printf("Iterations %d\n", iterations);
	iterations++; // This is called 60 times per second
}

bool Shoot::IsFinished()
{
	return solenoid->Get() == (push ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
/*
	return iterations > (int)(SECONDS_TO_WAIT * 60);
*/
}

void Shoot::End()
{
}

void Shoot::Interrupted()
{
}
