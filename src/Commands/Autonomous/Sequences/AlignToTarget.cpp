#include "AlignToTarget.h"

AlignToTarget::AlignToTarget() :
		PIDCommand("AlignToTarget", 0.001, 0.1, 0.1)
{
	Requires(Robot::vision.get());
	Requires(Robot::drivetrain.get());
	SetTimeout(8);
}

// Called just before this Command runs the first time
void AlignToTarget::Initialize()
{
	printf("test");
	GetPIDController()->SetAbsoluteTolerance(20);
	GetPIDController()->SetSetpoint(SCREEN_CENTER_X); //Point we're trying to get to
	GetPIDController()->Disable();
	GetPIDController()->SetOutputRange(-(ROT_SPEED_CAP - ROT_SPEED_MIN), ROT_SPEED_CAP - ROT_SPEED_MIN);
}

// Called repeatedly when this Command is scheduled to run
void AlignToTarget::Execute()
{
	printf("lol");

	//Only if we need to FIND a target
	//TODO: Add timeout so it doesn't keep trying forever
	if (!hasTarget)
	{
		hasTarget = Robot::vision.get()->UpdateCurrentTarget();
	}
	else
	{
		if (!GetPIDController()->IsEnabled())
		{
			PIDUserDisabled = false;
			//GetPIDController()->SetPID(1, 0, 0);
			GetPIDController()->SetPID(0.004, 0.0001, 0.003);
			GetPIDController()->Enable();
		}
		else
			printf("PID Enabled\n");
	}

}

//Inherited from PID Command, returns the input from the vision targets
double AlignToTarget::ReturnPIDInput()
{
	//Makes sure that the target still exists, if not, it goes bye bye
	std::shared_ptr<VisionTarget> target = Robot::vision->GetTrackedGoal();
	if (target == NULL)
	{
		PIDUserDisabled = true;
		hasTarget = false;
		GetPIDController()->Disable();
		return 0;
	}
	else
	{
		printf("Center X %u\n", target->GetCenter().x);
		return (double) target->GetCenter().x;
	}
}

void AlignToTarget::UsePIDOutput(double output)
{
	if (GetPIDController()->OnTarget())
		onTargetCounter++;
	else
		onTargetCounter = 0;

	printf("%f", output);

	if (output > 0)
		output += ROT_SPEED_MIN;
	else if (output < 0)
		output -= ROT_SPEED_MIN;

	if (!PIDUserDisabled && !IsFinished())
		Robot::drivetrain->SetTankDrive(output/2, -output);
	//printf("\noutput");

	SmartDashboard::PutNumber("AutoAlign Output", output);

	printf("wowowow %f, %u\n" , output, PIDUserDisabled);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignToTarget::IsFinished()
{
	return (onTargetCounter > 10);// || IsTimedOut();
	//Only end if the PID controller is done AND it HASN'T been user disabled (meaning it succeeded)
}

// Called once after isFinished returns true
void AlignToTarget::End()
{
	//TODO: Calculate launch angle and move the launcher here
	GetPIDController()->Disable();
	Robot::drivetrain->SetTankDrive(0, 0);
	//AlignLauncher();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignToTarget::Interrupted()
{
	GetPIDController()->Disable();
	Robot::drivetrain->SetTankDrive(0, 0);
	//Can't decide if I need to do anything else here
}
