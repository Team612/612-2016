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

	try //Used to report errors if navx does not work
	{
		navx = new AHRS(SPI::Port::kMXP); //startup navx
	}
	catch(std::exception ex) //catch any exceptions
	{
		DriverStation::ReportError("Error instantiating navX-MXP: " + ex.what()); //report to driver station
	}

	if(navx->IsConnected())
	{
		LiveWindow::GetInstance()->AddSensor("IMU", "Gyro", navx); //add sensor to livewindow
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
	if(navx->IsConnected())
	{
		//code derived from http://www.pdocs.kauailabs.com/navx-mxp/example/data-monitor/
		SmartDashboard::PutBoolean( "IMU_Connected",		navx->IsConnected());
		SmartDashboard::PutNumber(  "IMU_Yaw",      		navx->GetYaw());
		SmartDashboard::PutNumber(  "IMU_Pitch",    		navx->GetPitch());
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

		SmartDashboard::PutNumber(  "IMU_Roll",     		navx->GetRoll());
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
