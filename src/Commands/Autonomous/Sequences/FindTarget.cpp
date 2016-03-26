#include "FindTarget.h"

FindTarget::FindTarget(Direction d)
{
	Requires(Robot::drivetrain.get());
	Requires(Robot::vision.get());

	if (d == LEFT)
		dir = 1;
	else
		dir = -1;
}

// Called just before this Command runs the first time
void FindTarget::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FindTarget::Execute()
{
	Robot::vision->PullValues();
	Robot::drivetrain->SetTankDrive(-(dir * 0.4), (dir * 0.4));
}

// Make this return true when this Command no longer needs to run execute()
bool FindTarget::IsFinished()
{
	return Robot::vision->GetTargetAmount() > 0;
}

// Called once after isFinished returns true
void FindTarget::End()
{
	Robot::drivetrain->SetTankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FindTarget::Interrupted()
{
	Robot::drivetrain->SetTankDrive(0, 0);
}
