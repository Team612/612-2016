#include "BreachAuto.h"

BreachAuto::BreachAuto()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void BreachAuto::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BreachAuto::Execute()
{
	switch (defense)
	{
		case Robot::Defense::PORTCULLIS:
			break;
		case Robot::Defense::CHEVAL_DE_FRISE:
			break;
		case Robot::Defense::DRAW_BRIDGE:
			break;
		case Robot::Defense::LOW_BAR:
			break;
		case Robot::Defense::MOAT:
			break;
		case Robot::Defense::RAMPARTS:
			break;
		case Robot::Defense::ROCK_WALL:
			break;
		case Robot::Defense::SALLY_PORT:
			break;
		case Robot::Defense::ROUGH_TERRAIN:
			break;
		case Robot::Defense::NONE:
			break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BreachAuto::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void BreachAuto::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BreachAuto::Interrupted()
{

}
