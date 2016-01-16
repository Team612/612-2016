#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Robot.h"
#include "RobotMap.h"


void Robot::RobotInit()
{
	CommandBase::init(); // Constructor for CommandBase
	lw = LiveWindow::GetInstance();
	robot = this;
	autonomousCommand = NULL;
	try //instaniating navx pointer object
	{
		/* Communicate w/navX-MXP via the MXP SPI Bus.       */
	    /* Alternatively:  I2C::Port::kMXP, SerialPort::Port::kMXP or SerialPort::Port::kUSB */
	    /* See http://navx-mxp.kauailabs.com/guidance/selecting-an-interface/ for details.   */
	    navx = new NavX(SPI::Port::kMXP);
	}
	catch (std::exception ex ) //report errors to driver station
	{
		std::string err_string = "Error instantiating navX-MXP:  ";
		err_string += ex.what();
		DriverStation::ReportError(err_string.c_str());
	}
	//add sensor to livewindow if navx works
	if (navx) {
	     LiveWindow::GetInstance()->AddSensor("IMU", "Gyro", navx);
	}
}

void Robot::DisabledInit()
{
	robot_status = DISABLEDINIT; // Makes the status equal DISABLEDINIT
}

void Robot::DisabledPeriodic()
{
	if (robot_status != DISABLEDPERIODIC)
		robot_status = DISABLEDPERIODIC;
}

void Robot::AutonomousInit()
{
	robot_status = AUTONOMOUSINIT; // Makes the status equal AUTONOMOUSINIT
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic()
{
	if (robot_status != AUTONOMOUSPERIODIC) // Makes the status equal AUTONOMOUSPERIODIC
		robot_status = AUTONOMOUSPERIODIC;
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	printf("Teleopinit\n");
	robot_status = TELEOPINIT; // Makes the status equal TELEOPINIT
	/*
	 * This makes sure that the autonomous stops running when
	 * teleop starts running. If you want the autonomous to
	 * continue until interrupted by another command, remove
	 * this line or comment it out.
	 */
	if (autonomousCommand != NULL)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic()
{
	if (robot_status != TELEOPPERIODIC) // Makes the status equal TELEOPPERIODIC
		robot_status = TELEOPPERIODIC;
	Scheduler::GetInstance()->Run();
	lw->Run();
	if(navx->IsConnected()) //display values to driver station
	{
		SmartDashboard::PutBoolean( "IMU_Connected",		navx->IsConnected());
		SmartDashboard::PutNumber(  "IMU_Yaw",      		navx->GetYaw());
		SmartDashboard::PutNumber(  "IMU_Pitch",    		navx->GetPitch());
		SmartDashboard::PutNumber(  "IMU_Roll",     		navx->GetRoll());
		SmartDashboard::PutNumber(  "IMU_CompassHeading",   navx->GetCompassHeading());
		SmartDashboard::PutNumber(  "IMU_Update_Count",     navx->GetUpdateCount());
		SmartDashboard::PutNumber(  "IMU_Byte_Count",       navx->GetByteCount());

		/* These functions are compatible w/the WPI Gyro Class */
		SmartDashboard::PutNumber(  "IMU_TotalYaw", 		navx->GetAngle());
		SmartDashboard::PutNumber(  "IMU_YawRateDPS",       navx->GetRate());

		SmartDashboard::PutNumber(  "IMU_Accel_X",  		navx->GetWorldLinearAccelX());
		SmartDashboard::PutNumber(  "IMU_Accel_Y",  		navx->GetWorldLinearAccelY());
		SmartDashboard::PutBoolean( "IMU_IsMoving", 		navx->IsMoving());
		SmartDashboard::PutNumber(  "IMU_Temp_C",   		navx->GetTempC());
		SmartDashboard::PutBoolean( "IMU_IsCalibrating",    navx->IsCalibrating());

		SmartDashboard::PutNumber(  "Velocity_X",   		navx->GetVelocityX() );
		SmartDashboard::PutNumber(  "Velocity_Y",   		navx->GetVelocityY() );
		SmartDashboard::PutNumber(  "Displacement_X",       navx->GetDisplacementX() );
		SmartDashboard::PutNumber(  "Displacement_Y",       navx->GetDisplacementY() );
	}
}

void Robot::TestInit()
{
	robot_status = TESTINIT; // Makes the status equal TESTINIT
	printf("lel what are you even doing here scrub?\n");
}
void Robot::TestPeriodic()
{
	if (robot_status != TESTPERIODIC) // Makes the status equal TESTPERIODIC
		robot_status = TESTPERIODIC;
	lw->Run();
	//float val = joystick->GetRawAxis(5); //Takes input from joystick
	//firstTalon->Set(val); //Gives joystick input to first talon
	//secondTalon->Set(val);

}


START_ROBOT_CLASS(Robot);
