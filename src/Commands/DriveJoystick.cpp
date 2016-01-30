// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
/*This command gets two axis inputs from the left and right y-axis of the driver controller in OI, 
then adds a dead-zone (if axis value is within 0.1 of 0, make it 0). 
Finally, it sends this value to the SetTankDrive method of the drivetrain subsystem.
When it ends, or is interrupted, set SetTankDrive to 0, 0 to stop the robot. 
Also add a check using the Joystick::GetIsXbox method to change the y value axis 
if the controller is a joystick vs an xbox gamepad. */
#include "DriveJoystick.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveJoystick::DriveJoystick() :
		Command()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain.get());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveJoystick::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveJoystick::Interrupted()
{
	DriveJoystick::End();
	//is this possible in cpp? know this from java
}
