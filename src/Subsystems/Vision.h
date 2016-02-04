#ifndef Vision_H
#define Vision_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Vision: public Subsystem
{
private:
	std::shared_ptr<NetworkTable> table;

public:
	Vision(const char* initialCamera=CAMERA_FRONT);
	void InitDefaultCommand();
	void PullValues();
	void SetCamera(const char* camera);

	static constexpr char* CAMERA_FRONT = "cam0";
	static constexpr char* CAMERA_REAR = "cam1";
	static constexpr char* CAMERA_SHOOTER = "cam2";
};

#endif
