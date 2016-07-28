#pragma once

namespace IDS
{
	// Drivetrain Talons
	const int driveFL					= 1;  // CAN ID
	const int driveRL					= 2;  // CAN ID
	const int driveFR					= 3;  // CAN ID
	const int driveRR					= 4;  // CAN ID

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
	const int shooterAbsEncoder 		= 0;  // Analog Input

	const int shooterRotate 			= 5;  // CAN ID
	const int shooterIR 				= 1;  // Analog Input
	const int shooterActuatorLSwitch 	= 4;  // Digital Input
	const int shooterActuatorLSwitch2	= 5;  // Digital Input
	const int shooterActuatorMotor	 	= 5;  // CANTalon
	const int shooterSolenoid1			= 0;  // PCM Port
	const int shooterSolenoid2			= 1;  // PCM Port

	// Shooter Flywheels
	const int shooterFlyL 				= 6;  // CAN ID
	const int shooterFlyR 				= 7;  // CAN ID

	// Shooter Hall Effects
	const int shooterHallL 				= 6;  // Digital Input
	const int shooterHallR 				= 7;  // Digital Input

	// Arm
	const int armRotateMotor 			= 2;  //CAN ID

	//Spike
	const int shooterSpike 				= 0;  //Relay

	//Jetson
	const int jetsonI                   = 8;
	const int jetsonO                   = 9;

	//const SPI::Port NavX                = 0; //TODO Change depending on how NavX is wired!
}
