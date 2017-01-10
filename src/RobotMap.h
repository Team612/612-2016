#pragma once
#include <WPILib.h>
#include <Ports.h>
#include <AbsoluteEncoder.h>
#include <AHRS.h>
#include <TalonSRX.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap
{
public:
	static std::shared_ptr<TalonSRX> 		driveTalonFL;
	static std::shared_ptr<TalonSRX> 		driveTalonRL;
	static std::shared_ptr<TalonSRX> 		driveTalonFR;
	static std::shared_ptr<TalonSRX> 		driveTalonRR;
	static std::shared_ptr<Servo> 		shifterL;
	static std::shared_ptr<Servo> 		shifterR;
	static std::shared_ptr<Encoder> 	driveEncoderL;
	static std::shared_ptr<Encoder> 	driveEncoderR;
	static std::shared_ptr<RobotDrive> 	drivetrainRobotDrive;
	
	static std::shared_ptr<TalonSRX> 		shooterActuatorMotor;
	static std::shared_ptr<AbsoluteEncoder> shooterPotentiometer;
	static std::shared_ptr<TalonSRX> 		shooterRotateMotor;
	static std::shared_ptr<DoubleSolenoid>		shooterSolenoid;
	
	static std::shared_ptr<TalonSRX> flywheelMotorL;
	static std::shared_ptr<TalonSRX> flywheelMotorR;
	static std::shared_ptr<TalonSRX> armRotateMotor;

	static std::shared_ptr<AHRS> NavX;

	static constexpr float flywheelHallL = IDS::shooterHallL;
	static constexpr float flywheelHallR = IDS::shooterHallR;
	
	// TODO: These are only used in the Hall Effect control method
	//static constexpr float flywheelShootSpeed = 40.0f;
	//static constexpr float flywheelIntakeSpeed = -20.0f;

	static void init();
};

