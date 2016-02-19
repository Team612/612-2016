#include "Rumble.h"

Rumble::Rumble(OI::Stick stick, OI::RumbleSide side, float intensity, double time)
{
	SetTimeout(time);
	this->stick = stick;
	this->side = side;
	this->intensity = intensity;
}

// Called just before this Command runs the first time
void Rumble::Initialize()
{
	Robot::oi->RumbleStick(stick, side, intensity);
}

// Called repeatedly when this Command is scheduled to run
void Rumble::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool Rumble::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void Rumble::End()
{
	Robot::oi->RumbleStick(stick, side, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rumble::Interrupted()
{

}
