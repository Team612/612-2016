#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap
{
public:
	static std::shared_ptr<Talon> driveTalonFL;
	static std::shared_ptr<Talon> driveTalonRL;
	static std::shared_ptr<Talon> driveTalonFR;
	static std::shared_ptr<Talon> driveTalonRR;
	static std::shared_ptr<RobotDrive> drivetrainRobotDrive;
	static std::shared_ptr<Servo> shooterLever;
	static std::shared_ptr<AnalogInput> shooterEncoder;
	static std::shared_ptr<CANTalon> armMotor;
	static std::shared_ptr<AnalogInput> armRotationDetect;
	static std::shared_ptr<CANTalon> shooterRotateMotor;
	static std::shared_ptr<AnalogInput> shooterLeverDetect;
	static std::shared_ptr<Servo> shifterLeft;
	static std::shared_ptr<Servo> shifterRight;
	static std::shared_ptr<CANTalon> leftFlywheelMotor;
	static std::shared_ptr<CANTalon> rightFlywheelMotor;
	static std::shared_ptr<Encoder> driveEncoderLeft;
	static std::shared_ptr<Encoder> driveEncoderRight;
	static std::shared_ptr<USBCamera> cam1;
	static const int leftFlywheelHall = 6;
	static const int rightFlywheelHall = 7;
	static constexpr float flywheelShootSpeed = 40.0f;
	static constexpr float flywheelIntakeSpeed = -20.0f;

	static void init();
};
#endif
