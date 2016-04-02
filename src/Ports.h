#pragma once

namespace IDS
{
	// Drivetrain Talons
	const int driveFL					= 4;  // PWM Port
	const int driveRL					= 5;  // PWM Port
	const int driveFR					= 0;  // PWM Port
	const int driveRR					= 1;  // PWM Port

	// Drivetrain shifters
	const int shifterL					= 3;  // PWM Port
	const int shifterR 					= 2;  // PWM Port

	// Drive encoders
	const int driveEncoderL1			= 0;  // Digital Input Pin
	const int driveEncoderL2			= 1;  // Digital Input Pin
	const int driveEncoderR1			= 2;  // Digital Input Pin
	const int driveEncoderR2			= 3;  // Digital Input Pin

	// Shooter Misc
	const int shooterActuator			= 6;  // PWM Port
	const int shooterAbsEncoder 		= 3;  // Analog Input
	const int shooterRotate 			= 1;  // CAN ID
	const int shooterIR 				= 1;  // Analog Input
	const int shooterActuatorLSwitch 	= 4;  // Digital Input
	const int shooterActuatorLSwitch2	= 5;  // Digital Input
	const int shooterActuatorMotor	 	= 5;  //CANTalon

	// Shooter Flywheels
	const int shooterFlyL 				= 4;  // CAN ID
	const int shooterFlyR 				= 3;  // CAN ID

	// Shooter Hall Effects
	const int shooterHallL 				= 6;  // Digital Input
	const int shooterHallR 				= 7;  // Digital Input

	// Arm
	const int armRotateMotor 			= 2;  //CAN ID

	//Spike
	const int shooterSpike 				= 0;  //Relay
}
