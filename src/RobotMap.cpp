#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

std::shared_ptr<Talon> RobotMap::driveTalonFL;
std::shared_ptr<Talon> RobotMap::driveTalonRL;
std::shared_ptr<Talon> RobotMap::driveTalonFR;
std::shared_ptr<Talon> RobotMap::driveTalonRR;
std::shared_ptr<RobotDrive> RobotMap::drivetrainRobotDrive;
std::shared_ptr<Servo> RobotMap::shooterLever;
std::shared_ptr<CANTalon> RobotMap::armMotor;
std::shared_ptr<AnalogInput> RobotMap::armRotationDetect;
std::shared_ptr<CANTalon> RobotMap::shooterRotateMotor;
std::shared_ptr<AnalogInput> RobotMap::shooterLeverDetect;
std::shared_ptr<Servo> RobotMap::shifterLeft;
std::shared_ptr<Servo> RobotMap::shifterRight;
std::shared_ptr<CANTalon> RobotMap::leftFlywheelMotor;
std::shared_ptr<CANTalon> RobotMap::rightFlywheelMotor;
std::shared_ptr<Encoder> RobotMap::driveEncoderLeft;
std::shared_ptr<Encoder> RobotMap::driveEncoderRight;
std::shared_ptr<AnalogInput> RobotMap::shooterEncoder;
std::shared_ptr<USBCamera> RobotMap::cam1;

void RobotMap::init()
{
	LiveWindow *lw = LiveWindow::GetInstance();

	/* Servo values: 0
	 * Talon values: 1,2,3,4
	 *
	 *
	 * Talon and Servo both use PWM. Make sure their values are different!
	 */

	//PWM
	shooterLever.reset(new Servo(6));
	lw->AddActuator("ShooterLever", "Lever Servo", shooterLever);

	shifterRight.reset(new Servo(2));
	lw->AddActuator("Shifter", "Right Shifter Servo", shifterRight);

	shifterLeft.reset(new Servo(3));
		lw->AddActuator("Shifter", "Left Shifter Servo", shifterLeft);

	driveTalonFL.reset(new Talon(4)); // Front-left
	lw->AddActuator("Drivetrain", "Front Left (1)", driveTalonFL);

	driveTalonRL.reset(new Talon(5)); // Rear-left
	lw->AddActuator("Drivetrain", "Rear Left (2)", driveTalonRL);

	driveTalonFR.reset(new Talon(0)); // Front-right
	lw->AddActuator("Drivetrain", "Front Right (3)", driveTalonFR);

	driveTalonRR.reset(new Talon(1)); // Rear-right
	lw->AddActuator("Drivetrain", "Rear Right (4)", driveTalonRR);

	// Front-left, rear-left, front-right, rear-right
	drivetrainRobotDrive.reset(new RobotDrive(driveTalonFL, driveTalonRL,
			driveTalonFR, driveTalonRR));

	//CAN
	shooterRotateMotor.reset(new CANTalon(1));
	lw->AddActuator("ShooterRotate", "Shooter Rotate Motor", shooterRotateMotor);

	armMotor.reset(new CANTalon(2));
	lw->AddActuator("Arm", "Arm Motor", armMotor);

    rightFlywheelMotor.reset(new CANTalon(3));
	lw->AddActuator("ShooterWheels", "Right Flywheel Motor", rightFlywheelMotor);

	leftFlywheelMotor.reset(new CANTalon(4));
	lw->AddActuator("ShooterWheels", "Left Flywheel Motor", leftFlywheelMotor);

	 //Analog I/O
	shooterLeverDetect.reset(new AnalogInput(1));
	lw->AddActuator("ShooterLever", "Ball Detector IR", shooterLeverDetect);
	armRotationDetect.reset(new AnalogInput(3));
	lw->AddActuator("Arm", "Magnetic Encoder", armRotationDetect);
	shooterEncoder.reset(new AnalogInput(2));
	lw->AddActuator("ShooterRotation", "Shooter Rotation Encoder", shooterEncoder);

	drivetrainRobotDrive->SetSafetyEnabled(false);
	drivetrainRobotDrive->SetExpiration(0.1);
	drivetrainRobotDrive->SetSensitivity(0.5);
	drivetrainRobotDrive->SetMaxOutput(1.0);

	//Digital I/O
	driveEncoderLeft.reset(new Encoder(0, 1));
	lw->AddActuator("drivetrain", "Quad Encoder Left", driveEncoderLeft);

	driveEncoderRight.reset(new Encoder(2, 3));
	lw->AddActuator("drivetrain", "Quad Encoder Right", driveEncoderRight);
}
