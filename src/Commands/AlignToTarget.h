#ifndef AlignToTarget_H
#define AlignToTarget_H

#include "../Robot.h"
#include "WPILib.h"
#include "../VisionTarget.h"
#include <cmath>

class AlignToTarget: public PIDCommand //PID for rotation
{
public:
	AlignToTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

	double ReturnPIDInput();
	void UsePIDOutput(double output);

private:
	bool hasTarget = false; //If we are tracking a target
	bool PIDUserDisabled = true; //If the PID is disabled because it succeeded or because the code forced it off
	int onTargetCounter = 0;

	void FindTarget(); //Tries to fill the CurrentTarget variable
	//double AlignLauncher();
	const double TARGET_ASPECT = 1.66/1.00; //Aspect ratio of game-target (it's 1'8" x 1')
	const int SCREEN_CENTER_X = 320; //Center of the screen. This is the point to which we will rotate
								     //using PID.

	const double TARGET_HEIGHT = 0.305; //in meters
	const double TARGET_WIDTH  = 0.506; //in meters
	const double TARGET_HEIGHT_OFF_GROUND = 2; //in meters

	const double FOV_CAMERA = 35.4; //in degrees

	const double BOULDER_LAUNCH_SPEED = 12.9; //in meters per second

	const double ROT_SPEED_CAP = 0.7;
	const double ROT_SPEED_MIN = 0.5;
};

#endif
