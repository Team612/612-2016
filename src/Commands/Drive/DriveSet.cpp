#include "DriveSet.h"

DriveSet::DriveSet(float val1, float val2) :
		Command()
{
	Requires(Robot::drivetrain.get());

	outputPower = val1;
	curveSharpness = val2;
}
void DriveSet::Initialize() { }

void DriveSet::Execute()
{
	Robot::drivetrain->SetManualDrive(outputPower, curveSharpness);
}

bool DriveSet::IsFinished()
{
	return false;
}

void DriveSet::End()
{
	Robot::drivetrain->SetManualDrive(0.0f, 0.0f);
}

void DriveSet::Interrupted()
{
	Robot::drivetrain->SetManualDrive(0.0f,0.0f);
}
