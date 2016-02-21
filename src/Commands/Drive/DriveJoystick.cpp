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
#include <cmath>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveJoystick::DriveJoystick() :
		Command()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivetrain.get());
	leftPos = 0.0f;
	rightPos = 0.0f;
	//isXbox = Robot::oi->getDriver()->GetIsXbox();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveJoystick::Initialize()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
	//isFlipped = false;
}

// Called repeatedly when this Command is scheduled to run
void DriveJoystick::Execute()
{
	/*the way the drive system works, there should be a dead zone on both axes individually.
	 (i.e. if axis one is 0.08 and axis two is 0.6, then the output to the motors should be 0 and 0.6, not 0 and 0).
	 Finally, when i refer to Joystick, i am talking about the Joystick class which can be found here:
	 http://first.wpi.edu/FRC/roborio/release/docs/cpp/classJoystick.html
	 SetTankDrive, SetArcadeDrive, and SetManualDrive are all methods that will be put in the Drivetrain subststem file.
	 They will be called from commands. Commands are called in a few different ways.
	 They can be called automatically by a button press, they can be called by a command group,
	 or they can be called manually by calling the Command's Start() method. M
	 ore info on how this works can be found here:
	 http://wpilib.screenstepslive.com/s/4485/m/13810/l/241904-running-commands-on-joystick-input*/

	//if (!wasPressed && Robot::oi->getDriver()->GetRawButton(flipswitch)) {
	//	isFlipped = !isFlipped;
	//	wasPressed = true;
	//}	else wasPressed = false;
	//if (isXbox)
	//{
	leftPos = Robot::oi->getDriver()->GetRawAxis(01) * (-1);
	rightPos = Robot::oi->getDriver()->GetRawAxis(05) * (-1);

	//	if (isFlipped) {
	//		leftPos = -leftPos;
	//		rightPos = -rightPos;
	//	}

	if (leftPos > XDEADZONE)
	{
		leftPos = (leftPos - XDEADZONE) * ((float) 1 / ((float) 1 - XDEADZONE));
	}
	else if (leftPos < -XDEADZONE)
	{
		leftPos = (leftPos + XDEADZONE) * ((float) 1 / ((float) 1 - XDEADZONE));
	}
	else
		leftPos = 0.0f;
	//scale input to non-XDEADZONE area, unless within XDEADZONE in which input is set to 0

	if (rightPos > XDEADZONE)
	{
		rightPos = (rightPos - XDEADZONE)
				* ((float) 1 / ((float) 1 - XDEADZONE));
	}
	else if (rightPos < -XDEADZONE)
	{
		rightPos = (rightPos + XDEADZONE)
				* ((float) 1 / ((float) 1 - XDEADZONE));
	}
	else
		rightPos = 0.0f;

	if (Robot::drivetrain->GetInversion())
	{
		Robot::drivetrain->SetTankDrive(rightPos, leftPos);
	}
	else
		Robot::drivetrain->SetTankDrive(leftPos, rightPos);
	//}
	/*else
	 {
	 leftPos = Robot::oi->getDriver()->GetY();
	 rightPos = Robot::oi->getDriver()->GetTwist();

	 //	if (isFlipped) {
	 //		leftPos = -leftPos;
	 //		rightPos = -rightPos; //pretty sure rotation needs to flip
	 //	}

	 if (leftPos > JDEADZONE)
	 {
	 leftPos = (leftPos - JDEADZONE)
	 * ((float) 1 / ((float) 1 - JDEADZONE));
	 }
	 else if (leftPos < -JDEADZONE)
	 {
	 leftPos = (leftPos + JDEADZONE)
	 * ((float) 1 / ((float) 1 - JDEADZONE));
	 }
	 else
	 leftPos = 0.0f;
	 //scale input to non-JDEADZONE area, unless within JDEADZONE in which input is set to 0

	 if (rightPos > JDEADZONE)
	 {
	 rightPos = (rightPos - JDEADZONE)
	 * ((float) 1 / ((float) 1 - JDEADZONE));
	 }
	 else if (rightPos < -JDEADZONE)
	 {
	 rightPos = (rightPos + JDEADZONE)
	 * ((float) 1 / ((float) 1 - JDEADZONE));
	 }
	 else
	 rightPos = 0.0f;

	 //Checks if the driver wants to go backwards before applying values
	 //controls_inverted is set by the InvertControls command
	 if (Robot::drivetrain->GetInversion())
	 {
	 Robot::drivetrain->SetArcadeDrive(rightPos, leftPos);
	 }
	 else
	 Robot::drivetrain->SetArcadeDrive(leftPos, rightPos);
	 }*/
}

// Make this return true when this Command no longer needs to run execute()
bool DriveJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveJoystick::End()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
	//isFlipped = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveJoystick::Interrupted()
{
	Robot::drivetrain->SetTankDrive(0.0f, 0.0f);
	//isFlipped = false;
}

//bool DriveJoystick::IsBackwards() {
//	return isFlipped;
//}