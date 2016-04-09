#include <Commands/Autonomous/Sequences/HorizontalAlign.h>

HorizontalAlign::HorizontalAlign(float timeout) :
		PIDCommand("AlignToTarget", 0.004, 0, 0)
{
	Requires(Robot::drivetrain.get());
	SetTimeout(8);

	if(timeout != 0)
		SetTimeout(timeout);
}

void HorizontalAlign::Initialize()
{
	printf("test");
	auto pid = GetPIDController();
	pid->SetAbsoluteTolerance(40);
	pid->SetSetpoint(SCREEN_CENTER_X); //Point we're trying to get to
	pid->Disable();
	pid->SetOutputRange(-(ROT_SPEED_CAP - ROT_SPEED_MIN), ROT_SPEED_CAP - ROT_SPEED_MIN);
}

void HorizontalAlign::Execute()
{
	//Only if we need to FIND a target
	if (!hasTarget)
	{
		hasTarget = Robot::vision->UpdateCurrentTarget();
	}
	else
	{
		if (!GetPIDController()->IsEnabled())
		{
			PIDUserDisabled = false;
			//GetPIDController()->SetPID(1, 0, 0);
			auto pid = GetPIDController();
			pid->SetPID(SmartDashboard::GetNumber("dP", 0.004), SmartDashboard::GetNumber("dI", 0), SmartDashboard::GetNumber("dD", 0));
			pid->Enable();
		}
		else
			printf("PID Enabled\n");
	}

}

//Inherited from PID Command, returns the input from the vision targets
double HorizontalAlign::ReturnPIDInput()
{
	//Makes sure that the target still exists, if not, it goes bye bye
	std::shared_ptr<VisionTarget> target = Robot::vision->GetTrackedGoal();
	if (target == nullptr)
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

void HorizontalAlign::UsePIDOutput(double output)
{
	if (GetPIDController()->OnTarget())
	{
		onTargetCounter++;
	}
	else
	{
		onTargetCounter = 0;
	}
	SmartDashboard::PutNumber("OnTarget Counter", onTargetCounter);

	printf("%f", output);

	if (output > 0)
		output += ROT_SPEED_MIN;
	else if (output < 0)
		output -= ROT_SPEED_MIN;

	if (!PIDUserDisabled && !IsFinished())
		Robot::drivetrain->SetTankDrive(output, -output);
	//printf("\noutput");

	SmartDashboard::PutNumber("AutoAlign Output", output);

	printf("wowowow %f, %u\n" , output, PIDUserDisabled);
}

bool HorizontalAlign::IsFinished()
{
	return (onTargetCounter > 10);// || IsTimedOut();
	//Only end if the PID controller is done AND it HASN'T been user disabled (meaning it succeeded)
}

void HorizontalAlign::End()
{
	//TODO: Calculate launch angle and move the launcher here
	GetPIDController()->Disable();
	Robot::drivetrain->SetTankDrive(0, 0);
}

void HorizontalAlign::Interrupted()
{
	GetPIDController()->Disable();
	Robot::drivetrain->SetTankDrive(0, 0);
}
