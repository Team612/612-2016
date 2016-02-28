#include "SetServoPosition.h"

SetServoPosition::SetServoPosition(ShooterServoPosition pos)
{
    //Requires(Robot::shooterlever.get());
    // TODO: These values need to be tested: 0 for clamp, .5 for neutral, 1 for push.
    this->position = pos;
}

// Called just before this Command runs the first time
void SetServoPosition::Initialize()
{
  /* TODO: Fix the following code.
   * LeverServo1 is the object, but it is not necessary to call it here.
   * The ShooterLever subsystem provides the SetServoAngle(angle)
   * method.
   */
	Robot::shooterlever.get()->SetPosition(position);
}

// Called repeatedly when this Command is scheduled to run
void SetServoPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetServoPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetServoPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetServoPosition::Interrupted()
{

}
