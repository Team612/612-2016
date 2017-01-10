#pragma once

#include "Commands/Subsystem.h"
#include "RobotDrive.h"
#include "WPILib.h"
#include <TalonSRX.h>

class Drivetrain: public Subsystem
{
private:
	bool controls_inverted;
	std::shared_ptr<TalonSRX> Talon1;
	std::shared_ptr<TalonSRX> Talon2;
	std::shared_ptr<TalonSRX> Talon3;
	std::shared_ptr<TalonSRX> Talon4;
	std::shared_ptr<RobotDrive> robotDrive;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<Encoder> encoder2;
public:
	Drivetrain();
	void SetManualDrive(float outputPower, float curveSharpness);
	void SetArcadeDrive(float movePower, float rotatePower);
	void SetTankDrive(float leftPower, float rightPower);
	void SetInversion(bool is_inverted);
	void Stop();
	bool GetInversion();
	double GetEncoderDistance();
	double GetEncoder2Distance();
	double GetAverageEncoderDistance();
	void InitDefaultCommand();
	std::shared_ptr<TalonSRX> GetTalons(int id);

	void PIDDisable();
	void PIDEnable();
};


