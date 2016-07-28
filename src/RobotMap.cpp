#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include <map>
#include <string>

std::shared_ptr<CANTalon>  	RobotMap::driveTalonFL;
std::shared_ptr<CANTalon> 		RobotMap::driveTalonRL;
std::shared_ptr<CANTalon> 		RobotMap::driveTalonFR;
std::shared_ptr<CANTalon> 		RobotMap::driveTalonRR;
std::shared_ptr<Servo> 		RobotMap::shifterL;
std::shared_ptr<Servo> 		RobotMap::shifterR;
std::shared_ptr<Encoder> 	RobotMap::driveEncoderL;
std::shared_ptr<Encoder> 	RobotMap::driveEncoderR;
std::shared_ptr<RobotDrive> RobotMap::drivetrainRobotDrive;

std::shared_ptr<CANTalon>       	RobotMap::shooterActuatorMotor;
std::shared_ptr<AbsoluteEncoder>	RobotMap::shooterPotentiometer;
std::shared_ptr<CANTalon>    		RobotMap::shooterRotateMotor;
std::shared_ptr<DoubleSolenoid>		RobotMap::shooterSolenoid;

std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorL;
std::shared_ptr<CANTalon> 	RobotMap::flywheelMotorR;

std::shared_ptr<CANTalon> RobotMap::armRotateMotor;

std::shared_ptr<AHRS> RobotMap::NavX;

void RobotMap::init()
{
	//LiveWindow *lw = LiveWindow::GetInstance();

	driveTalonFL.reset(new CANTalon(IDS::driveFL)); // Front-left
	driveTalonRL.reset(new CANTalon(IDS::driveRL)); // Rear-left
	driveTalonFR.reset(new CANTalon(IDS::driveFR)); // Front-right
	driveTalonRR.reset(new CANTalon(IDS::driveRR)); // Rear-right
	
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
	shooterPotentiometer.reset(new AbsoluteEncoder(IDS::shooterPotentiometer));
	shooterRotateMotor.reset(new CANTalon(IDS::shooterRotate));
    shooterSolenoid.reset(new DoubleSolenoid(IDS::shooterSolenoid1, IDS::shooterSolenoid2));
	
	flywheelMotorL.reset(new CANTalon(IDS::shooterFlyL));
    flywheelMotorR.reset(new CANTalon(IDS::shooterFlyR));

    armRotateMotor.reset(new CANTalon(IDS::armRotateMotor));

    NavX.reset(new AHRS(SPI::Port::kMXP));
}
