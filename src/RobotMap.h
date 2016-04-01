#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include <WPILib.h>
#include <Ports.h>
#include <AbsoluteEncoder/AbsoluteEncoder.h>
#include <NavX/AHRS.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap
{
public:
	static std::shared_ptr<Talon> 		driveTalonFL;
	static std::shared_ptr<Talon> 		driveTalonRL;
	static std::shared_ptr<Talon> 		driveTalonFR;
	static std::shared_ptr<Talon> 		driveTalonRR;
	static std::shared_ptr<Servo> 		shifterL;
	static std::shared_ptr<Servo> 		shifterR;
	static std::shared_ptr<Encoder> 	driveEncoderL;
	static std::shared_ptr<Encoder> 	driveEncoderR;
	static std::shared_ptr<RobotDrive> 	drivetrainRobotDrive;
	
	static std::shared_ptr<CANTalon> 		shooterActuatorMotor;
	static std::shared_ptr<AbsoluteEncoder> shooterAbsEncoder;
	static std::shared_ptr<CANTalon> 		shooterRotateMotor;
	static std::shared_ptr<AnalogInput> 	shooterIR;
	static std::shared_ptr<DigitalInput>	shooterActuatorLSwitch;
	static std::shared_ptr<DigitalInput>	shooterActuatorLSwitch2;
	static std::shared_ptr<Relay>           shooterSpike;
	
	static std::shared_ptr<CANTalon> flywheelMotorL;
	static std::shared_ptr<CANTalon> flywheelMotorR;
	static std::shared_ptr<CANTalon> armRotateMotor;

	static std::shared_ptr<AHRS> NavX;

	static constexpr float flywheelHallL = IDS::shooterHallL;
	static constexpr float flywheelHallR = IDS::shooterHallR;
	
	// TODO: These are only used in the Hall Effect control method
	static constexpr float flywheelShootSpeed = 40.0f;
	static constexpr float flywheelIntakeSpeed = -20.0f;

	static void init();
};
#endif
