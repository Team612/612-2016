#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../VisionTarget.h"
#include <vector>

class Vision: public Subsystem
{
private:
	std::shared_ptr<NetworkTable> table;
	std::vector<std::shared_ptr<VisionTarget>> targets;

	std::shared_ptr<VisionTarget> goal;

	const float TARGET_ASPECT = 1.66/1.00;

public:
	Vision();
	void InitDefaultCommand();
	void PullValues();
	void SetCamera(const char* camera);

	std::vector<std::shared_ptr<VisionTarget>> GetAllTargets(); //List all detected vision targets
	int GetTargetAmount(); //Amount of detected vision targets (targets.size())
	std::shared_ptr<VisionTarget> GetTargetById(int id); //Get target by it's RoboRealm tracking ID
	bool TargetExists(int id); //Check if an ID exists

	//Camera constants, assume front is side with launcher
	//static constexpr char* CAMERA_FRONT = "cam0";
	//static constexpr char* CAMERA_REAR = "cam1";
	//static constexpr char* CAMERA_SHOOTER = "cam2";
	/*
	 * Also, using char* as a string is deprecated so this completely FLOODS the console
	 *
	 *
	 *
	 * I am so sorry
	 */

	std::shared_ptr<NetworkTable> GetRawTable();

	bool UpdateCurrentTarget();
	std::shared_ptr<VisionTarget> GetTrackedGoal();
};

#endif
