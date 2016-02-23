#include "ArmToPosition.h"
#include <cmath>

/*
 * I ported Ben Ward's cheap PID-like movement code
 * to this command. Thanks Ben!
 * It may be a good idea to make sure to set the arm to
 * neutral (0 degrees) before this command is called.
 */

ArmToPosition::ArmToPosition(float position)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm.get());
	this->position = position;
	power = 0.7f;
}

// Called just before this Command runs the first time
void ArmToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmToPosition::Execute()
{
	if(abs(Robot::arm.get()->GetDegrees() - position) < THREASHHOLD)
		power /= SCALE;

	/*
	 * The following if block:
	 * if the degree position of the arm is less than the position needed but not in the "close enough" range (i.e. not far enough)
	 *     Set the motor to power
	 * if the degree position of the arm is greater than the position needed but not in the "close enough" range (i.e. too far)
	 *     Set the motor to negative power
	 * if the degree position of the arm is in the "close enough" range (3 degrees for now)
	 *     Stop the motor
	 *
	 * All the while the power is being degrees by a factor of 3/2 every iteration.
	 */

	if(Robot::arm.get()->GetDegrees() < position && !(abs(Robot::arm.get()->GetDegrees() - position) < (position + CLOSE_ENOUGH) && abs(Robot::arm.get()->GetDegrees() - position) > (position - CLOSE_ENOUGH)))
		Robot::arm.get()->adjust->Set(power);
	else if(Robot::arm.get()->GetDegrees() > position && !(abs(Robot::arm.get()->GetDegrees() - position) < (position + CLOSE_ENOUGH) && abs(Robot::arm.get()->GetDegrees() - position) > (position - CLOSE_ENOUGH)))
		Robot::arm.get()->adjust->Set(power * -1);
	else if (abs(Robot::arm.get()->GetDegrees() - position) < (position + CLOSE_ENOUGH) && abs(Robot::arm.get()->GetDegrees() - position) > (position - CLOSE_ENOUGH))
	{
		Robot::arm.get()->adjust->Set(0);
		std::printf("Arm set to position")
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmToPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmToPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmToPosition::Interrupted()
{

}
