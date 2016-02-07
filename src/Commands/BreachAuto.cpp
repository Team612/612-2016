#include "BreachAuto.h"

BreachAuto::BreachAuto(Robot::Defense defense)
{
	Requires(Robot::drivetrain.get());
	this->defense = defense;
}

void BreachAuto::Initialize()
{

}

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
		default:
			break;
	}
}

bool BreachAuto::IsFinished()
{
	return true;
}

void BreachAuto::End()
{

}

void BreachAuto::Interrupted()
{

}
