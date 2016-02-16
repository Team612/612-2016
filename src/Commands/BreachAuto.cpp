#include "BreachAuto.h"

BreachAuto::BreachAuto(Robot::Defense _defense)
{
	Requires(Robot::drivetrain.get());
	defense = _defense;
}

void BreachAuto::Initialize()
{

}

void BreachAuto::BreachPortcullis()
{

}

void BreachAuto::BreachChevalDeFrise()
{

}

void BreachAuto::BreachMoat()
{

}

void BreachAuto::BreachRamparts()
{

}

void BreachAuto::BreachDrawBridge()
{

}

void BreachAuto::BreachSallyPort()
{

}

void BreachAuto::BreachRockWall()
{

}

void BreachAuto::BreachRoughTerrain()
{

}

void BreachAuto::BreachLowBar()
{

}

void BreachAuto::BreachNone()
{

}

void BreachAuto::Execute()
{
	switch (defense)
	{
		case Robot::Defense::PORTCULLIS:
			BreachPortcullis();
			break;
		case Robot::Defense::CHEVAL_DE_FRISE:
			BreachChevalDeFrise();
			break;
		case Robot::Defense::DRAW_BRIDGE:
			BreachDrawBridge();
			break;
		case Robot::Defense::LOW_BAR:
			BreachLowBar();
			break;
		case Robot::Defense::MOAT:
			BreachMoat();
			break;
		case Robot::Defense::RAMPARTS:
			BreachRamparts();
			break;
		case Robot::Defense::ROCK_WALL:
			BreachRockWall();
			break;
		case Robot::Defense::SALLY_PORT:
			BreachSallyPort();
			break;
		case Robot::Defense::ROUGH_TERRAIN:
			BreachRoughTerrain();
			break;
		case Robot::Defense::NONE:
			BreachNone();
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
