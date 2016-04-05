#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../VisionTarget.h"
#include <vector>
#include "DigitalOutput.h"

class Vision: public Subsystem
{
private:
	std::shared_ptr<NetworkTable> table = NULL;
	std::vector<std::shared_ptr<VisionTarget>> targets;

	std::shared_ptr<VisionTarget> goal;

	const float TARGET_ASPECT = 1.66/1.00;

public:
	Vision();
	void InitDefaultCommand();
	void PullValues();
	void SetCamera(const char* camera);

	const std::string BOUNDING_KEY = "BOUNDING_COORDINATES";
	const std::string IDS_KEY = "IDS";

	std::vector<std::shared_ptr<VisionTarget>> GetAllTargets(); //List all detected vision targets
	int GetTargetAmount(); //Amount of detected vision targets (targets.size())
	std::shared_ptr<VisionTarget> GetTargetById(int id); //Get target by it's ID in our jank Python program
	bool TargetExists(int id); //Check if an ID exists
	bool TargetExists(std::shared_ptr<VisionTarget> target);

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
	void SetTrackedGoal(std::shared_ptr<VisionTarget>);
	void SetTrackingID(int id);
	int GetTrackingID();
};
#endif
