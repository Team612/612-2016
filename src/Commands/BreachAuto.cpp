#include "BreachAuto.h"

BreachAuto::BreachAuto(Robot::Defense _defense)
{
	Requires(Robot::drivetrain.get());
	defense = _defense;
}

void BreachAuto::Initialize()
{

}

void BreachAuto::Execute()
{
	switch (defense)
	{
		case Robot::Defense::PORTCULLIS:
			Robot::drivetrain.get()->BreachPortcullis();
			break;
		case Robot::Defense::CHEVAL_DE_FRISE:
			Robot::drivetrain.get()->BreachChevalDeFrise();
			break;
		case Robot::Defense::DRAW_BRIDGE:
			Robot::drivetrain.get()->BreachDrawBridge();
			break;
		case Robot::Defense::LOW_BAR:
			Robot::drivetrain.get()->BreachLowBar();
			break;
		case Robot::Defense::MOAT:
			Robot::drivetrain.get()->BreachMoat();
			break;
		case Robot::Defense::RAMPARTS:
			Robot::drivetrain.get()->BreachRamparts();
			break;
		case Robot::Defense::ROCK_WALL:
			Robot::drivetrain.get()->BreachRockWall();
			break;
		case Robot::Defense::SALLY_PORT:
			Robot::drivetrain.get()->BreachSallyPort();
			break;
		case Robot::Defense::ROUGH_TERRAIN:
			Robot::drivetrain.get()->BreachRoughTerrain();
			break;
		case Robot::Defense::NONE:
			Robot::drivetrain.get()->BreachNone();
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
