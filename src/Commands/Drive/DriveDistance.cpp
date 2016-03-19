#include "DriveDistance.h"
#include "Robot.h"

DriveDistance::DriveDistance(float end_distance) : PIDCommand("DriveDistance", 0.2, 0.0, 0.0) //default values
{
	Requires(Robot::drivetrain.get());
	// TODO: Should this use both encoders?
	RobotMap::driveEncoderL->Reset();
	this->end_distance = end_distance;

	GetPIDController()->SetContinuous(true); //?
	GetPIDController()->SetOutputRange(-1.0f, 1.0f);
}

void DriveDistance::Initialize()
{
	GetPIDController()->SetSetpoint(end_distance); //point we are trying to get to
	Robot::drivetrain.get()->SetTankDrive(SPEED, SPEED);
	GetPIDController()->SetInputRange(STARTING_DISTANCE, end_distance);
	GetPIDController()->Enable();

}

void DriveDistance::Execute()
{
	std::printf("PID Value: %f\n",  GetPIDController()->Get()); //debugging
}

bool DriveDistance::IsFinished()
{
	return GetPIDController()->OnTarget();
}

void DriveDistance::End()
{
	// TODO: Should this use both encoders?
	RobotMap::driveEncoderL->Reset();
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);

	GetPIDController()->Disable();
}

void DriveDistance::Interrupted()
{
	std::printf("ERROR: DriveDistance interrupted!\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);

	GetPIDController()->Disable();
}

double DriveDistance::ReturnPIDInput()
{
	return Robot::drivetrain.get()->GetEncoderDistance();
}

void DriveDistance::UsePIDOutput(double output)
{
	Robot::drivetrain.get()->SetTankDrive(output, output);
}
