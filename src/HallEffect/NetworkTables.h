#ifndef SRC_HALLEFFECT_NETWORKTABLES_H_
#define SRC_HALLEFFECT_NETWORKTABLES_H_

#include <chrono>
//#include <Stringref>
#include <WPILib.h>
//#include <NetworkTables/NetworkTable.h>

class NetworkTables
{
public:
	NetworkTables();
	//void Initialize();
	void AddValue(double val);

private:
	std::shared_ptr<NetworkTable> wheels;
	std::chrono::high_resolution_clock::time_point startTime;
};

#endif /* SRC_HALLEFFECT_NETWORKTABLES_H_ */
