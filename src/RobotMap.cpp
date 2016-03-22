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
		// PWM
    	{ "driveFL", 			    4 },
    	{ "driveRL", 			    5 },
    	{ "driveFR", 			    0 },
    	{ "driveLR", 			    1 },
    	{ "shifterL", 			    3 },
    	{ "shifterR", 			    2 },
    	// Digital I/O
    	{ "driveEncoderL1", 	    0 },
    	{ "driveEncoderL2", 	    1 },
    	{ "driveEncoderR1", 	    2 },
    	{ "driveEncoderR2", 	    3 },
		{ "shooterActuatorLSwitch", 4 },
    	{ "shooterHallL", 		    6 },
    	{ "shooterHallR", 		    7 },
    	// Analog I/O
    	{ "shooterAbsEncoder",  	2 },
    	{ "shooterIR", 		    	1 },
    	// CAN
    	{ "shooterRotate", 		    1 },
    	{ "shooterFlyL", 		    4 },
    	{ "shooterActuatorMotor", 	6 },
    	{ "shooterFlyR", 		    3 }
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
	
	flywheelMotorL.reset(new CANTalon(ports["shooterFlyL"]));
    flywheelMotorR.reset(new CANTalon(ports["shooterFlyR"]));

    shooterActuatorLSwitch.reset(new DigitalInput(ports["shooterActuatorLSwitch"]));
}
