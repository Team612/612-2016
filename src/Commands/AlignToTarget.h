#ifndef AlignToTarget_H
#define AlignToTarget_H

#include "../Robot.h"
#include "WPILib.h"

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
	std::shared_ptr<VisionTarget> currentTarget; //Currently tracked target (=NULL if no target)

	void FindTarget(); //Tries to fill the CurrentTarget variable
	double CalculateDistance();
	const double TARGET_ASPECT = 1.66/1.17; //Aspect ratio of game-target (it's 1'8" x 1'2")
	const int SCREEN_CENTER_X = 320; //Center of the screen. This is the point to which we will rotate
								     //using PID.
};

#endif
