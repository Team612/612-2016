#include <Commands/Autonomous/Sequences/HorizontalFind.h>

HorizontalFind::HorizontalFind(Direction d, float timeout)
{
	Requires(Robot::drivetrain.get());
	Requires(Robot::vision.get());

	if (d == LEFT)
		dir = 1;
	else
		dir = -1;

	if (timeout != 0)
		SetTimeout(timeout);
}

// Called just before this Command runs the first time
void HorizontalFind::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HorizontalFind::Execute()
{
	Robot::vision->PullValues();
	Robot::drivetrain->SetTankDrive(-(dir * 0.4), (dir * 0.4));
}

// Make this return true when this Command no longer needs to run execute()
bool HorizontalFind::IsFinished()
{
	return Robot::vision->GetTargetAmount() > 0;
}

// Called once after isFinished returns true
void HorizontalFind::End()
{
	Robot::drivetrain->SetTankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HorizontalFind::Interrupted()
{
	Robot::drivetrain->SetTankDrive(0, 0);
}
