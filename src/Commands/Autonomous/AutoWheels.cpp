#include "AutoWheels.h"
#include "Robot.h"

AutoWheels::AutoWheels()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::shooterwheels.get());
}

// Called just before this Command runs the first time
void AutoWheels::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoWheels::Execute()
{
	auto gunner = Robot::oi->getGunner()->GetRawAxis(1);
	if(gunner > TOLERANCE)
		Robot::shooterwheels->SetWheelSpeed(RobotMap::flywheelShootSpeed);
	else if (gunner < -TOLERANCE)
		Robot::shooterwheels->SetWheelSpeed(RobotMap::flywheelIntakeSpeed);
	else
		Robot::shooterwheels->SetWheelSpeed(0.0);
//	if(Robot::oi->getGunner()->GetRawAxis(3) > TOLERANCE) //Left trigger pressed down
//	{
//		Robot::shooterwheels->SetWheelSpeed(RobotMap::flywheelShootSpeed);
////		std::printf("FLYWHEEL->SHOOT\n");
//	}
//	else if(Robot::oi->getGunner()->GetRawAxis(2) > TOLERANCE) //Right trigger pressed down
//	{
//		Robot::shooterwheels->SetWheelSpeed(RobotMap::flywheelIntakeSpeed);
////		std::printf("FLYWHEEL->INTAKE\n");
//	}
//	else if(Robot::oi->getGunner()->GetRawAxis(2) < TOLERANCE && Robot::oi->getGunner()->GetRawAxis(3) < TOLERANCE) //both released
//	{
//	    Robot::shooterwheels->SetWheelSpeed(0.0f);
////	    std::printf("FLYWHEEL->STOP\n");
//	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoWheels::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoWheels::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoWheels::Interrupted()
{

}
