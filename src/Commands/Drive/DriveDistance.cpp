#include "DriveDistance.h"
#include "Robot.h"

DriveDistance::DriveDistance(float end_distance) : PIDCommand("DriveDistance", 1.0, 0.0, 0.0) //default values
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain.get());
	RobotMap::drivetrainEncoder->Reset();
	this->end_distance = end_distance;

	GetPIDController()->SetContinuous(true); //?
}

// Called just before this Command runs the first time
void DriveDistance::Initialize()
{
	GetPIDController()->SetSetpoint(end_distance); //point we are trying to get to
	Robot::drivetrain.get()->SetTankDrive(SPEED, SPEED);
	GetPIDController()->SetInputRange(STARTING_DISTANCE, end_distance);
	GetPIDController()->Enable();

}

// Called repeatedly when this Command is scheduled to run
void DriveDistance::Execute()
{
	std::printf("PID Value: %f\n",  GetPIDController()->Get());

}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished()
{
	return GetPIDController()->OnTarget();
}

// Called once after isFinished returns true
void DriveDistance::End()
{
	RobotMap::drivetrainEncoder->Reset();
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted()
{
	std::printf("ERROR: DriveDistance interrupted!\n");
	Robot::drivetrain.get()->SetTankDrive(0.0f, 0.0f);
}

double DriveDistance::ReturnPIDInput()
{
	return Robot::drivetrain.get()->GetEncoderDistance();
}

void DriveDistance::UsePIDOutput(double output)
{
	Robot::drivetrain.get()->SetTankDrive(output, output);
}
