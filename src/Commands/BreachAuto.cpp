#include "BreachAuto.h"

BreachAuto::BreachAuto(Robot::Defense defense)
{
	Requires(Robot::drivetrain.get());
	Requires(Robot::arm.get());
	this->defense = defense;
	time = new Timer();
}

void BreachAuto::Initialize()
{
	time->Reset(); //safety
	time->Start();
}

void BreachAuto::Execute()
{
	switch (defense)
	{
		case Robot::Defense::PORTCULLIS:
			//needs arm, do once PID loop is figured out
			//lower arm to ground
			//drive forwards
			//raise arm (and gate)
			//drive forward
			//reset arm
			break;
		case Robot::Defense::CHEVAL_DE_FRISE:
			//needs arm, do once PID loop is figured out
			//raise arm
			//drive forward
			//lower arm
			//drive forward
			//reset arm
			break;
		case Robot::Defense::DRAW_BRIDGE:
			//needs arm, do once PID loop is figured out
			//lower arm to ground
			//drive forwards
			//raise arm (and gate)
			//drive forward
			//reset arm
			break;
		case Robot::Defense::LOW_BAR:
			if(time->Get() < 3)
			{
				Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
			}
			break;
		case Robot::Defense::MOAT:
			if(time->Get() < 5)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
			}
			break;
		case Robot::Defense::RAMPARTS:
			if(time->Get() < 5)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
			}
			break;
		case Robot::Defense::ROCK_WALL:
			if(time->Get() < 5)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
			}
			break;
		case Robot::Defense::SALLY_PORT:
			//needs arm, do once PID loop is figured out
			//raise arm
			//drive forward
			//lower arm (on sally port)
			//drive backward (open gate)
			//drive forward (through gate)
			break;
		case Robot::Defense::ROUGH_TERRAIN:
			if(time->Get() < 5)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
			}
			break;
		case Robot::Defense::NONE:
			//leave blank for now
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
	time->Stop();
	//delete time;
}

void BreachAuto::Interrupted()
{
	time->Stop();
	delete time;
}
