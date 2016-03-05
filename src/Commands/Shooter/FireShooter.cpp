#include "FireShooter.h"

FireShooter::FireShooter(ShooterServoPosition pos)
{
    Requires(Robot::shooterlever.get());
    // TODO: These values need to be tested: 0 for clamp, .5 for neutral, 1 for push.
    this->position = pos;
}

// Called just before this Command runs the first time
void FireShooter::Initialize()
{
  /* TODO: Fix the following code.
   * LeverServo1 is the object, but it is not necessary to call it here.
   * The ShooterLever subsystem provides the SetServoAngle(angle)
   * method.
   */
	Robot::shooterlever->SetPosition(position);
	count = 0;
}

// Called repeatedly when this Command is scheduled to run
void FireShooter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FireShooter::IsFinished()
{
	if(position == ShooterServoPosition::Neutral)
		return true;
	if(Robot::shooterlever->AtSetPosition())
		count++;
	return count >= 30;
}

// Called once after isFinished returns true
void FireShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireShooter::Interrupted()
{

}
