#include "BreachAuto.h"

BreachAuto::BreachAuto(Robot::Defense defense)
{
	Requires(Robot::drivetrain.get());
	Requires(Robot::arm.get());
	this->defense = defense;
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
	Robot::drivetrain->SetTankDrive(1.0f, 1.0f);  // Stub to be tuned later
}

void BreachAuto::BreachRamparts()
{
	Robot::drivetrain->SetTankDrive(1.0f, 1.0f);  // Stub to be tuned later
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
	Robot::drivetrain->SetTankDrive(1.0f, 1.0f);
}

void BreachAuto::BreachLowBar()
{
	Robot::drivetrain->SetTankDrive(1.0f, 1.0f);
}

void BreachAuto::BreachNone()
{
	// Robot::drivetrain->Stop(); To be implemented later if necessary
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
