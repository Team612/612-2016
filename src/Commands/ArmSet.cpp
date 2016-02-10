#include "ArmSet.h"

ArmSet::ArmSet(float val1, float val2) : Command()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::arm.get());
	power = val1;
	time = val2;
}

// Called just before this Command runs the first time
void ArmSet::Initialize()
{
	myTimer.Stop();
	myTimer.Reset();
	myTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void ArmSet::Execute()
{
	if ((float)myTimer.Get() <= time) {
		Robot::arm->moveArm(power);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmSet::IsFinished()
{
	return (myTimer.Get() <= time);
}

// Called once after isFinished returns true
void ArmSet::End()
{
	Robot::arm->moveArm(0.0f);
	myTimer.Stop();
	myTimer.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmSet::Interrupted()
{
	Robot::arm->moveArm(0.0f);
	myTimer.Stop();
}
