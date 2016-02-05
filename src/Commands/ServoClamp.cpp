#include "ServoClamp.h"

ServoClamp::ServoClamp()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
    Requires(Robot::shooterlever.get());
}

// Called just before this Command runs the first time
void ServoClamp::Initialize()
{
  /* TODO: Fix the following code.
   * LeverServo1 is the object, but it is not necessary to call it here.
   * The ShooterLever subsystem provides the SetServoAngle(angle)
   * method.
   */
	Robot::shooterlever.get()->  LeverServo1(0.0f);
}

// Called repeatedly when this Command is scheduled to run
void ServoClamp::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ServoClamp::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ServoClamp::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ServoClamp::Interrupted()
{

}
