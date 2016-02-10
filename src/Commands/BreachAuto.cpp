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
		case Robot::Defense::CHEVAL_DE_FRISE:
			Robot::drivetrain.get()->BreachChevalDeFrise();
		case Robot::Defense::DRAW_BRIDGE:
			Robot::drivetrain.get()->BreachDrawBridge();
		case Robot::Defense::LOW_BAR:
			Robot::drivetrain.get()->BreachLowBar();
		case Robot::Defense::MOAT:
			Robot::drivetrain.get()->BreachMoat();
		case Robot::Defense::RAMPARTS:
			Robot::drivetrain.get()->BreachRamparts();
		case Robot::Defense::ROCK_WALL:
			Robot::drivetrain.get()->BreachRockWall();
		case Robot::Defense::SALLY_PORT:
			Robot::drivetrain.get()->BreachSallyPort();
		case Robot::Defense::ROUGH_TERRAIN:
			Robot::drivetrain.get()->BreachRoughTerrain();
		case Robot::Defense::NONE:
			Robot::drivetrain.get()->BreachNone();
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
