#include "Drivetrain.h"
#include "../RobotMap.h"
#include "Commands/Drive/DriveJoystick.h"

Drivetrain::Drivetrain() :
		Subsystem("Drivetrain")
{
	Talon1 = RobotMap::driveTalonFL;
	Talon2 = RobotMap::driveTalonRL;
	Talon3 = RobotMap::driveTalonFR;
	Talon4 = RobotMap::driveTalonRR;
	robotDrive = RobotMap::drivetrainRobotDrive;
	encoder = RobotMap::driveEncoderL;
	encoder2 = RobotMap::driveEncoderR;
	controls_inverted = false;
	robotDrive->SetSafetyEnabled(false);
}

void Drivetrain::InitDefaultCommand()
{
	SetDefaultCommand(new DriveJoystick());
}

void Drivetrain::SetTankDrive(float leftPower, float rightPower)
{
	robotDrive->TankDrive(leftPower, rightPower);
}

void Drivetrain::SetArcadeDrive(float movePower, float rotatePower)
{
	robotDrive->ArcadeDrive(movePower, rotatePower);
}

void Drivetrain::SetManualDrive(float outputPower, float curveSharpness)
{
    robotDrive->Drive(outputPower, curveSharpness);
}

void Drivetrain::SetInversion(bool is_inverted)
{
	Talon1->SetInverted(is_inverted);
	Talon2->SetInverted(is_inverted);
	Talon3->SetInverted(is_inverted);
	Talon4->SetInverted(is_inverted);

	controls_inverted = is_inverted;
}

void Drivetrain::Stop() {
	SetManualDrive(0, 0);
}

bool Drivetrain::GetInversion()
{
	if (Talon1->GetInverted() && Talon2->GetInverted() && Talon3->GetInverted() && Talon4->GetInverted())
	{
		return true;
	}
	else if (!Talon1->GetInverted() && !Talon2->GetInverted() && !Talon3->GetInverted() && !Talon4->GetInverted())
	{
		return false;
	}
	else
	{
		SetInversion(false); // To ensure that output is predictable in the event of an unexpected issue, I did this
		return false;
	}
}

double Drivetrain::GetEncoderDistance()
{
	return encoder->Get()/20; //this is so we can change this later
}

double Drivetrain::GetEncoder2Distance()
{
	return encoder2->Get()/20;
}

double Drivetrain::GetAverageEncoderDistance()
{
	return ((this->GetEncoderDistance()) + (this->GetEncoderDistance()))/2;
}

std::shared_ptr<TalonSRX> Drivetrain::GetTalons(int id)
{
	switch(id)
	{
		case 1: return RobotMap::driveTalonFL;
				break;
		case 2: return RobotMap::driveTalonRL;
				break;
		case 3: return RobotMap::driveTalonFR;
				break;
		case 4: return RobotMap::driveTalonRR;
				break;
		default:
			printf("Talon ID out of range in Drivetrain::GetTalons");
			return 0;
			break;
	}
}

