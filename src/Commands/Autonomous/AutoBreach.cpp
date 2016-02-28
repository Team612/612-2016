#include "AutoBreach.h"

AutoBreach::AutoBreach(Robot::Defense defense)
{
	Requires(Robot::arm.get());
	Requires(Robot::drivetrain.get());

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.
	switch(defense)
	{
		case Robot::Defense::PORTCULLIS:
				//needs arm, do once PID loop is figured out
				//lower arm to ground
				AddSequential(new ArmToPosition(1.0f));
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
				AddSequential(new ArmToPosition(0.5f));
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
				//reset arm
				AddSequential(new ArmToPosition(0.0f));
			break;
		case Robot::Defense::CHEVAL_DE_FRISE:
				//needs arm, do once PID loop is figured out
				//raise arm
				AddSequential(new ArmToPosition(0.5f));
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
				AddSequential(new ArmToPosition(0.0f));
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
				//reset arm
			break;
		case Robot::Defense::DRAW_BRIDGE:
				//needs arm, do once PID loop is figured out
				//lower arm to ground
				AddSequential(new ArmToPosition(1.0f));
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
				AddSequential(new ArmToPosition(0.5f));
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
				//reset arm
				AddSequential(new ArmToPosition(0.0f));
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
				time->Reset();
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
				time->Reset();
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
				time->Reset();
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
			AddSequential(new ArmToPosition(0.5f));
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
			AddSequential(new ArmToPosition(1.0f));
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


	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
