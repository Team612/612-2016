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
std::shared_ptr<DigitalInput>       RobotMap::shooterActuatorLSwitch2;
std::shared_ptr<AbsoluteEncoder>	RobotMap::shooterAbsEncoder;
std::shared_ptr<CANTalon>    		RobotMap::shooterRotateMotor;
std::shared_ptr<AnalogInput> 		RobotMap::shooterIR;
std::shared_ptr<Relay>              RobotMap::shooterSpike;

std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorL;
std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorR;

std::shared_ptr<CANTalon> RobotMap::armRotateMotor;

void RobotMap::init()
{
	//LiveWindow *lw = LiveWindow::GetInstance();

	driveTalonFL.reset(new Talon(IDS::driveFL)); // Front-left
	driveTalonRL.reset(new Talon(IDS::driveRL)); // Rear-left
	driveTalonFR.reset(new Talon(IDS::driveFR)); // Front-right
	driveTalonRR.reset(new Talon(IDS::driveRR)); // Rear-right
	
	shifterL.reset(new Servo(IDS::shifterL));
	shifterR.reset(new Servo(IDS::shifterR));

	driveEncoderL.reset(new Encoder(IDS::driveEncoderL1, IDS::driveEncoderL2));
	driveEncoderR.reset(new Encoder(IDS::driveEncoderR1, IDS::driveEncoderR2));
	
	// Front-left, rear-left, front-right, rear-right
	drivetrainRobotDrive.reset(new RobotDrive(driveTalonFL, driveTalonRL,
			driveTalonFR, driveTalonRR));

	drivetrainRobotDrive->SetSafetyEnabled(false);
	drivetrainRobotDrive->SetExpiration(0.1);
	drivetrainRobotDrive->SetSensitivity(0.5);
	drivetrainRobotDrive->SetMaxOutput(1.0);

	shooterActuatorMotor.reset(new CANTalon(IDS::shooterActuatorMotor));
	shooterAbsEncoder.reset(new AbsoluteEncoder(IDS::shooterAbsEncoder));
	shooterRotateMotor.reset(new CANTalon(IDS::shooterRotate));
	shooterIR.reset(new AnalogInput(IDS::shooterIR));
    shooterActuatorLSwitch.reset(new DigitalInput(IDS::shooterActuatorLSwitch));
    shooterActuatorLSwitch2.reset(new DigitalInput(IDS::shooterActuatorLSwitch2));
    shooterSpike.reset(new Relay(IDS::shooterSpike, Relay::Direction::kForwardOnly));
	
	flywheelMotorL.reset(new CANTalon(IDS::shooterFlyL));
    flywheelMotorR.reset(new CANTalon(IDS::shooterFlyR));

    armRotateMotor.reset(new CANTalon(IDS::armRotateMotor));
}
