#include "Vision.h"
#include "../RobotMap.h"

Vision::Vision(const char* camera) :
		Subsystem("Vision")
{
	NetworkTable::SetPort(1735);
	table = NetworkTable::GetTable("Vision");
	CameraServer::GetInstance()->SetQuality(100);
	SetCamera(camera);
}



void Vision::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Vision::PullValues()
{
	llvm::ArrayRef<double> arr;
	std::vector<double> vec = table->GetNumberArray("BOUNDING_COORDINATES", arr);

	for(int x = 0; x < vec.size(); x++) {
		printf("%u ", (int)vec[x]);
	}

	printf("\n");

	printf("Key 0: %u \n", table->ContainsKey("BOUNDING_COORDINATES"));
}

void Vision::SetCamera(const char* camera)
{
	CameraServer::GetInstance()->StartAutomaticCapture(camera);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
