#ifndef SIMPLEAUTONOMOUS_H_
#define SIMPLEAUTONOMOUS_H_

#include "WPILib.h"
#include "Robot.h"

class SimpleAutonomous : public Command {
public:
	SimpleAutonomous(float time, float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float time;
	float speed;
	Timer* autoTime;
	float start_time;
	float current_time;

};



#endif /* SRC_COMMANDS_AUTONOMOUS_AUTONOMOUS_H_ */
