#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include <map>
#include <string>

std::shared_ptr<Talon>  	RobotMap::driveTalonFL;
std::shared_ptr<Talon> 		RobotMap::driveTalonRL;
std::shared_ptr<Talon> 		RobotMap::driveTalonFR;
std::shared_ptr<Talon> 		RobotMap::driveTalonRR;
std::shared_ptr<Servo> 		RobotMap::shifterL;
std::shared_ptr<Servo> 		RobotMap::shifterR;
std::shared_ptr<Encoder> 	RobotMap::driveEncoderL;
std::shared_ptr<Encoder> 	RobotMap::driveEncoderR;
std::shared_ptr<RobotDrive> RobotMap::drivetrainRobotDrive;

std::shared_ptr<Servo>       		RobotMap::shooterActuator;
std::shared_ptr<AbsoluteEncoder>	RobotMap::shooterAbsEncoder;
std::shared_ptr<CANTalon>    		RobotMap::shooterRotateMotor;
std::shared_ptr<AnalogInput> 		RobotMap::shooterIR;

std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorL;
std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorR;

std::shared_ptr<USBCamera> 	RobotMap::cam1;

std::map<std::string, int> RobotMap::ports;

void RobotMap::init()
{
	LiveWindow *lw = LiveWindow::GetInstance();
	
	ports = {
		// Drive train Talons
    	{ "driveFL", 			4 }, // PWM Port
    	{ "driveRL", 			5 }, // PWM Port
    	{ "driveFR", 			0 }, // PWM Port
    	{ "driveLR", 			1 }, // PWM Port
    	// Drive shifter servos
    	{ "shifterL", 			3 }, // PWM Port
    	{ "shifterR", 			2 }, // PWM Port
    	// Drive encoders
    	{ "driveEncoderL1", 	0 }, // Digital Input Pin
    	{ "driveEncoderL2", 	1 }, // Digital Input Pin
    	{ "driveEncoderR1", 	2 }, // Digital Input Pin
    	{ "driveEncoderR2", 	3 }, // Digital Input Pin
    	// Shooter Misc
    	{ "shooterActuator", 	6 }, // PWM Port
    	{ "shooterAbsEncoder", 	2 }, // Analog Input
    	{ "shooterRotate", 		1 }, // CAN ID
    	{ "shooterIR", 			1 }, // Analog Input
    	// Shooter Flywheels
    	{ "shooterFlyL", 		4 }, // CAN ID
    	{ "shooterFlyR", 		3 }, // CAN ID
    	// Shooter Hall Effects
    	{ "shooterHallL", 		6 },
    	{ "shooterHallR", 		7 }
	};

	driveTalonFL.reset(new Talon(ports["driveFL"])); // Front-left
	driveTalonRL.reset(new Talon(ports["driveRL"])); // Rear-left
	driveTalonFR.reset(new Talon(ports["driveFR"])); // Front-right
	driveTalonRR.reset(new Talon(ports["driveRR"])); // Rear-right
	
	shifterL.reset(new Servo(ports["shifterL"]));
	shifterR.reset(new Servo(ports["shifterR"]));

	driveEncoderL.reset(new Encoder((int)(ports["driveEncoderL1"]), (int)(ports["driveEncoderL2"])));
	driveEncoderR.reset(new Encoder((int)(ports["driveEncoderR1"]), (int)(ports["driveEncoderR2"])));
	
	// Front-left, rear-left, front-right, rear-right
	drivetrainRobotDrive.reset(new RobotDrive(driveTalonFL, driveTalonRL,
			driveTalonFR, driveTalonRR));
			
	drivetrainRobotDrive->SetSafetyEnabled(false);
	drivetrainRobotDrive->SetExpiration(0.1);
	drivetrainRobotDrive->SetSensitivity(0.5);
	drivetrainRobotDrive->SetMaxOutput(1.0);


	shooterActuator.reset(new Servo(ports["shooterActuator"]));
	shooterAbsEncoder.reset(new AbsoluteEncoder(ports["shooterAbsEncoder"]));
	shooterRotateMotor.reset(new CANTalon(ports["shooterRotate"]));
	shooterIR.reset(new AnalogInput(ports["shooterIR"]));
	
	flywheelMotorL.reset(new CANTalon(ports["shooterFlyL"]));
    flywheelMotorR.reset(new CANTalon(ports["shooterFlyR"]));
}
