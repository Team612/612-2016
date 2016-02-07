#include "AlignToTarget.h"

AlignToTarget::AlignToTarget() : PIDCommand("AlignToTarget", 1, 0, 0)
{
	Requires(Robot::vision.get());
}

// Called just before this Command runs the first time
void AlignToTarget::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AlignToTarget::Execute()
{
	//Populate VisionTarget vector
	Robot::vision->PullValues();

	//Only if we need to FIND a target
	//TODO: Add timeout so it doesn't keep trying forever
	if (!hasTarget)
	{
		std::shared_ptr<NetworkTable> table = Robot::vision->GetRawTable();

		llvm::ArrayRef<double> arr;

		//See Vision subsystem for info on why we have to check for this and why we don't look
		//at 1-8
		if (table->GetNumberArray("BOUNDING_COORDINATES", arr).size() > 8)
		{
			FindTarget();
		}
	}
	else
	{
		if (!GetPIDController()->IsEnabled())
		{
			GetPIDController()->SetSetpoint(SCREEN_CENTER_X); //Point we're trying to get to
			GetPIDController()->SetAbsoluteTolerance(10); //Within 10 pixels of the actual box
			PIDUserDisabled = false;
			GetPIDController()->Enable();
		}
	}


}

void AlignToTarget::FindTarget()
{
	//Only executes if RoboRealm has actually detected targets
	if (Robot::vision->GetTargetAmount() > 0) {
		//Uses the FindClosestAspect static method to find the target with the closest aspect ratio to that of the real target
		currentTarget = VisionTarget::FindClosestAspect(TARGET_ASPECT, Robot::vision->GetAllTargets());
		hasTarget = true;
	}
}

double AlignToTarget::CalculateDistance() {
	//TODO: this
}


//Inherited from PID Command, returns the input from the vision targets
double AlignToTarget::ReturnPIDInput() {
	//Makes sure that the target still exists, if not, it goes bye bye
	if (!Robot::vision->TargetExists(currentTarget->GetID()))
	{
		hasTarget = false;
		PIDUserDisabled = true;
		currentTarget = NULL;
		GetPIDController()->Disable();
	}


	return currentTarget->GetCenter().x;
}

void AlignToTarget::UsePIDOutput(double output) {
	//TODO: Make this rotate the bot
}

// Make this return true when this Command no longer needs to run execute()
bool AlignToTarget::IsFinished()
{
	return !GetPIDController()->IsEnabled() && !PIDUserDisabled;
	//Only end if the PID controller is done AND it HASN'T been user disabled (meaning it succeeded)
}

// Called once after isFinished returns true
void AlignToTarget::End()
{
	//TODO: Calculate launch angle and move the launcher here
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignToTarget::Interrupted()
{
	GetPIDController()->Disable();
	//Can't decide if I need to do anything else here
}
