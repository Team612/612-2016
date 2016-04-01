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
}

void Shoot::Initialize()
{
	solenoid->Set(push ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
}

void Shoot::Execute()
{
}

bool Shoot::IsFinished()
{
	return solenoid->Get() == (push ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
}

void Shoot::End()
{
}

void Shoot::Interrupted()
{
}
