#include "AutoBreach.h"

AutoBreach::AutoBreach(Robot::Defense defense)
{
	Requires(Robot::drivetrain.get());

	/*
	 *
	 */

	//float all_out = 4.0f;
	//float all_in = 1.1f;
	//float half = 4;

	switch(defense)
	{
		case Robot::Defense::PORTCULLIS:
				//needs arm, do once PID loop is figured out
				//lower arm to ground
				//AddSequential(new ArmToPosition(all_out));
				//drive forwards
				time->Start();
				if(time->Get() < 3000)
				{
					Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
				}
				else
				{
					Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
					time->Stop();
					time->Reset();
				}
				//raise arm (and gate)
				//AddSequential(new ArmToPosition(half));

				//drive forward
				time->Start();
				if(time->Get() < 3000)
				{
					Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
				}
				else
				{
					Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
					time->Stop();
					//time->Reset();
				}
				//reset arm
				//AddSequential(new ArmToPosition(all_in));
			break;
		case Robot::Defense::CHEVAL_DE_FRISE:
				//needs arm, do once PID loop is figured out
				//raise arm
				//AddSequential(new ArmToPosition(half));

				//drive forward
				time->Start();
				if(time->Get() < 3000)
				{
					Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
				}
				else
				{
					Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
					time->Stop();
					time->Reset();
				}
				//lower arm
				//AddSequential(new ArmToPosition(all_in));
				//drive forward
				time->Start();
				if(time->Get() < 3000)
				{
					Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
				}
				else
				{
					Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
					time->Stop();
					//time->Reset();
				}
				//reset arm
			break;
		case Robot::Defense::DRAW_BRIDGE:
				//needs arm, do once PID loop is figured out
				//lower arm to ground
				//AddSequential(new ArmToPosition(all_out));
				//drive forwards
				time->Start();
				if(time->Get() < 3000)
				{
					Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
				}
				else
				{
					Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
					time->Stop();
					time->Reset();
				}
				//raise arm (and gate)
				//AddSequential(new ArmToPosition(half));
				//drive forward
				time->Start();
				if(time->Get() < 3000)
				{
					Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
				}
				else
				{
					Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
					time->Stop();
					//time->Reset();
				}
				//reset arm
				//AddSequential(new ArmToPosition(all_in));
			break;
		case Robot::Defense::LOW_BAR:
			time->Start();
			if(time->Get() < 3000)
			{
				Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
				time->Stop();
				//time->Reset();
			}
			break;
		case Robot::Defense::MOAT:
			time->Start();
			if(time->Get() < 5000)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
				time->Stop();
				//time->Reset();
			}
			break;
		case Robot::Defense::RAMPARTS:
			time->Start();
			if(time->Get() < 5000)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
				time->Stop();
				//time->Reset();
			}
			break;
		case Robot::Defense::ROCK_WALL:
			if(time->Get() < 5000)
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
			//AddSequential(new ArmToPosition(half));
				//drive forward
			time->Start();
			if(time->Get() < 3000)
			{
				Robot::drivetrain->SetArcadeDrive(0.7f, 0.7f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
				time->Stop();
				time->Reset();
			}
				//lower arm (on sally port)
			//AddSequential(new ArmToPosition(all_out));
				//drive backward (open gate)
			time->Start();
			if(time->Get() < 3000)
			{
				Robot::drivetrain->SetArcadeDrive(-0.7f, -0.7f);
			}
			else
			{
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
				time->Stop();
				time->Reset();
			}
				//drive forward (through gate)
			break;
		case Robot::Defense::ROUGH_TERRAIN:
			time->Start();
			if(time->Get() < 5000)
			{
				Robot::drivetrain->SetArcadeDrive(1.0f, 1.0f);
			}
			else
			{
				time->Stop();
				time->Reset();
				Robot::drivetrain->SetArcadeDrive(0.0f, 0.0f);
			}
			break;
		case Robot::Defense::NONE:
				//leave blank for now
			break;
		default:
			break;
	}
	//add parallel?
}
