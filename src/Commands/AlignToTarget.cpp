#include "AlignToTarget.h"

AlignToTarget::AlignToTarget() :
		PIDCommand("AlignToTarget", 0.001, 0.1, 0.1)
{
	Requires(Robot::vision.get());
	Requires(Robot::drivetrain.get());
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
			PIDUserDisabled = false;
			GetPIDController()->SetPID(0.008, 0.0001, 0.003);
			GetPIDController()->Enable();
		}
		else
			printf("PID Enabled");
	}

}

void AlignToTarget::FindTarget()
{
	//Only executes if RoboRealm has actually detected targets
	if (Robot::vision->GetTargetAmount() > 0)
	{
		//Uses the FindClosestAspect static method to find the target with the closest aspect ratio to that of the real target
		currentTarget = VisionTarget::FindClosestAspect(TARGET_ASPECT,
			Robot::vision->GetAllTargets());
		hasTarget = true;
	}
}

void AlignToTarget::AlignLauncher()
{
	double h = currentTarget->GetHeight();
	double x = (0.0001592*pow(h, 2)) - (0.06046*h) + 6.9204;
	printf("\nDistance Calculation: %f", x);
	double y = TARGET_HEIGHT_OFF_GROUND;
	double v = BOULDER_LAUNCH_SPEED;
	double g = 9.8; //gravity
	double sq = pow(v, 4) - (g * (g * (x * x) + 2 * y * (v * v)));
	if (sq >= 0)
	{
		sq = sqrt(sq);
		double angleInRadians = atan(((v * v) - sq) / (g * x));
		double angleInDegrees = angleInRadians * (180 / M_PI);
		printf("\nDegree Calculation: %f", angleInDegrees);
	}
}

//Inherited from PID Command, returns the input from the vision targets
double AlignToTarget::ReturnPIDInput()
{
	//Makes sure that the target still exists, if not, it goes bye bye
	if (!Robot::vision->TargetExists(currentTarget->GetID()))
	{
		hasTarget = false;
		PIDUserDisabled = true;
		currentTarget = NULL;
		GetPIDController()->Disable();
		Robot::drivetrain->SetTankDrive(0, 0);
		return 0;
	}

	printf("Center X %u", currentTarget->GetCenter().x);
	return (double) currentTarget->GetCenter().x;
}

void AlignToTarget::UsePIDOutput(double output)
{
	if (GetPIDController()->OnTarget())
		onTargetCounter++;
	else
		onTargetCounter = 0;

	printf("%f", output);
	if (output >= 0)
		output = ROT_SPEED_MIN;
	else
		output -= ROT_SPEED_MIN;
	if (!PIDUserDisabled && !IsFinished())
		Robot::drivetrain->SetTankDrive(output, -output);
	printf("\noutput");

	//printf("wowowow %f\n" , output);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignToTarget::IsFinished()
{
	return onTargetCounter > 10;
	//Only end if the PID controller is done AND it HASN'T been user disabled (meaning it succeeded)
}

// Called once after isFinished returns true
void AlignToTarget::End()
{
	//TODO: Calculate launch angle and move the launcher here
	Robot::drivetrain->SetTankDrive(0, 0);
	AlignLauncher();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignToTarget::Interrupted()
{
	GetPIDController()->Disable();
	Robot::drivetrain->SetTankDrive(0, 0);
	//Can't decide if I need to do anything else here
}
