#include "ArmToPosition.h"
#include "Robot.h"
#include <cmath>

/*
 * I ported Ben Ward's cheap PID-like movement code
 * to this command. Thanks Ben!
 * It may be a good idea to make sure to set the arm to
 * neutral (0 degrees) before this command is called.
 *
 * Note that this is completely temporary!
 */

ArmToPosition::ArmToPosition(float position) //from 0 to 1
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm.get());
	this->position = position; //set
	power = 0.7f;


}

// Called just before this Command runs the first time
void ArmToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmToPosition::Execute()
{
	if(abs(Robot::arm.get()->getArmPosition() - position) < THRESHOLD)
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

	if(Robot::arm.get()->getArmPosition() < position && !(abs(Robot::arm.get()->getArmPosition() - position) < (position + CLOSE_ENOUGH) && abs(Robot::arm.get()->getArmPosition() - position) > (position - CLOSE_ENOUGH)))
		RobotMap::armAdjust->Set(power);
	else if(Robot::arm.get()->GetDegrees() > position && !(abs(Robot::arm.get()->getArmPosition() - position) < (position + CLOSE_ENOUGH) && abs(Robot::arm.get()->getArmPosition() - position) > (position - CLOSE_ENOUGH)))
		RobotMap::armAdjust->Set(power * -1);

}

// Make this return true when this Command no longer needs to run execute()
bool ArmToPosition::IsFinished()
{
	return abs(Robot::arm.get()->getArmPosition() - position) < (position + CLOSE_ENOUGH) && abs(Robot::arm.get()->getArmPosition() - position) > (position - CLOSE_ENOUGH);
}

// Called once after isFinished returns true
void ArmToPosition::End()
{
	RobotMap::armAdjust->Set(0);
	std::printf("Arm set to position\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmToPosition::Interrupted()
{
	RobotMap::armAdjust->Set(0);
	std::printf("ERROR: Arm movement interrupted!\n");
}
