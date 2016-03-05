#include "ShooterTest.h"
#include "../../Robot.h"

ShooterTest::ShooterTest()
{
	Requires(Robot::shooterrotation.get());
}

// Called just before this Command runs the first time
void ShooterTest::Initialize()
{
	Robot::shooterrotation->SetPIDEnabled(false);
	Robot::shooterrotation->SetPID(SmartDashboard::GetNumber("P", 0), SmartDashboard::GetNumber("I", 0), SmartDashboard::GetNumber("D", 0));
	Robot::shooterrotation->SetAngle(SmartDashboard::GetNumber("Angle", 0));
	Robot::shooterrotation->SetPIDEnabled(true);
}

// Called repeatedly when this Command is scheduled to run
void ShooterTest::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterTest::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ShooterTest::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterTest::Interrupted()
{

}
