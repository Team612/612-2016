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

std::shared_ptr<CANTalon>       	RobotMap::shooterActuatorMotor;
std::shared_ptr<DigitalInput>       RobotMap::shooterActuatorLSwitch;
std::shared_ptr<AbsoluteEncoder>	RobotMap::shooterAbsEncoder;
std::shared_ptr<CANTalon>    		RobotMap::shooterRotateMotor;
std::shared_ptr<AnalogInput> 		RobotMap::shooterIR;

std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorL;
std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorR;

std::shared_ptr<USBCamera> 	RobotMap::cam1;

std::map<std::string, int> RobotMap::ports;

void RobotMap::init()
{
	//LiveWindow *lw = LiveWindow::GetInstance();
	
	ports = {
		// Drive train
    	{ "driveFL", 			    4 }, // PWM port
    	{ "driveRL", 			    5 }, // PWM port
    	{ "driveFR", 			    0 }, // PWM port
    	{ "driveLR", 			    1 }, // PWM port
		// Drive train shifters
    	{ "shifterL", 			    3 }, // PWM port
    	{ "shifterR", 			    2 }, // PWM port
		// Drive train encoders
    	{ "driveEncoderL1", 	    0 }, // Digital pin
    	{ "driveEncoderL2", 	    1 }, // Digital pin
    	{ "driveEncoderR1", 	    2 }, // Digital pin
    	{ "driveEncoderR2", 	    3 }, // Digital pin
		// Shooter
    	{ "shooterActuatorMotor", 	5 }, // CAN ID
    	{ "shooterAbsEncoder",  	2 }, // Analog In
    	{ "shooterRotate", 		    1 }, // CAN ID
    	{ "shooterIR", 		    	1 }, // Analog In
		{ "shooterActuatorLSwitch", 4 }, // Digital pin
		// Shooter flywheels
    	{ "shooterFlyL", 		    4 }, // CAN ID
    	{ "shooterFlyR", 		    3 }, // CAN ID
    	{ "shooterHallL", 		    6 }, // Digital pin
    	{ "shooterHallR", 		    7 }  // Digital pin
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


	shooterActuatorMotor.reset(new CANTalon(ports["shooterActuatorMotor"]));
	shooterAbsEncoder.reset(new AbsoluteEncoder(ports["shooterAbsEncoder"]));
	shooterRotateMotor.reset(new CANTalon(ports["shooterRotate"]));
	shooterIR.reset(new AnalogInput(ports["shooterIR"]));
    shooterActuatorLSwitch.reset(new DigitalInput(ports["shooterActuatorLSwitch"]));
	
	flywheelMotorL.reset(new CANTalon(ports["shooterFlyL"]));
    flywheelMotorR.reset(new CANTalon(ports["shooterFlyR"]));
}
