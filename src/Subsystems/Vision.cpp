#include "Vision.h"
#include "../RobotMap.h"
#include "Robot.h"

Vision::Vision() :
		Subsystem("Vision")
{
	NetworkTable::SetPort(1735); //I think this is the default port but just to be safe
	table = NetworkTable::GetTable("Vision");


	// \/ Comment this bit out if we haven't bothered to plug a camera in \/
	//CameraServer::GetInstance()->SetQuality(50);
	//SetCamera(camera);
	goal = NULL;
}

void Vision::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Vision::PullValues()
{
	//If bounding coordinates actually exist in the table, if not, all of this will throw errors and
	//everyone will die
	printf("test1\n");

	llvm::ArrayRef<double> arr;
	std::vector<double> coords = table->GetNumberArray(BOUNDING_KEY,
			arr);
	/* Okay, so this is a thing that is long enough that I had to make a block comment. Basically,
	 * RoboRealm doesn't automatically overwrite the BOUNDING_COORDINATES variable (which makes
	 * literally no sense because it updates every single other variable just fine). In order to
	 * bypass this, I was forced to DELETE the table every tick so RoboRealm would populate it
	 * with new values. Unfortunately, the tick speed on the RoboRealm is faster than the framerate
	 * of the camera, hence the constant checking of whether or not bounding coordinates actually
	 * exist.
	 */

	llvm::ArrayRef<double> arr2;
	std::vector<double> ids = table->GetNumberArray(IDS_KEY, arr2);
	//An array of all things being tracked, conveniently in the same order as the bounding coords

	int targetCount = ids.size();

	//Loop to create/update VisionTargets with new bound coords
	for (int x = 0; x < targetCount; x++)
	{
		printf("test2");
		std::vector<int> vec;
		for (int i = 0; i < VisionTarget::PARAM_COUNT; i++)
		{
			vec.push_back((int) coords[(x * VisionTarget::PARAM_COUNT) + i]);
		}

		//Only updates if it finds that the ID already exists
		if (TargetExists(ids[x]))
		{
			GetTargetById(ids[x])->Print();
			GetTargetById(ids[x])->Set(vec);
		}
		//If the ID is new then we make a new target
		else
			targets.push_back(
					std::shared_ptr<VisionTarget>(
							new VisionTarget(vec, ids[x])));
	}

	printf("\n");

	//Goes through and deletes all of the VisionTargets that no longer exist in RoboRealm
	for (uint32_t x = 0; x < targets.size(); x++)
	{
		bool found = false;
		for (uint32_t i = 0; i < ids.size(); i++)
		{
			if (targets[x]->GetID() == ids[i])
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			targets.erase(targets.begin() + x);
			x--;
		}
	}
}

void Vision::SetCamera(const char* camera)
{
	//This only works once because I can't figure out how to STOP automatic capture
	//I might have to do it manually (i.e. image by image)
	//Which would suck
	CameraServer::GetInstance()->StartAutomaticCapture(camera);
}

std::vector<std::shared_ptr<VisionTarget>> Vision::GetAllTargets()
{
	return targets;
}

std::shared_ptr<VisionTarget> Vision::GetTargetById(int id)
{
	//Iterate through and return target with that ID
	for (uint32_t x = 0; x < targets.size(); x++)
	{
		if (targets[x]->GetID() == id)
			return targets[x];
	}

	return NULL;
}

bool Vision::TargetExists(int id)
{
	//Basically does the same thing as the above method but with a bool
	//I could probably just use the above method to get results for this one
	for (uint32_t x = 0; x < targets.size(); x++)
	{
		if (targets[x]->GetID() == id)
			return true;
	}

	return false;
}

bool Vision::TargetExists(std::shared_ptr<VisionTarget> target)
{
	return TargetExists(target->GetID());
}

std::shared_ptr<NetworkTable> Vision::GetRawTable()
{
	return table;
}

int Vision::GetTargetAmount()
{
	return targets.size();
}

bool Vision::UpdateCurrentTarget()
{
	llvm::ArrayRef<double> arr;

	if (GetTargetAmount() > 0)
	{
		goal = VisionTarget::FindClosestAspect(TARGET_ASPECT, GetAllTargets());
		std::printf("Info: UpdateCurrentTarget()\n");
		return true;
	}
	else
	{
		std::printf("Warning: No vision target\n");
		return false;
	}
}

std::shared_ptr<VisionTarget> Vision::GetTrackedGoal()
{
	if (goal == NULL || !TargetExists(goal->GetID()))
	{
		UpdateCurrentTarget();
	}

	return goal;
}

void Vision::SetTrackedGoal(std::shared_ptr<VisionTarget> goal)
{
	this->goal = goal;
}

void Vision::SetTrackingID(int id)
{
	std::shared_ptr<VisionTarget> target = GetTargetById(id);
	if (target == NULL)
	{
		printf("Warning: No goal found with ID %u\n", id);
		printf("Info: Attempting to set automatically...\n");
		UpdateCurrentTarget();
	}
	else
	{
		goal = target;
	}
}

int Vision::GetTrackingID()
{
	if (goal != NULL)
		return goal->GetID();
	else
		return -1;
}
