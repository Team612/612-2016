#include "ActuatorActivate.h"
#include "RobotMap.h"
#include "Robot.h"

ActuatorActivate::ActuatorActivate()
{
	Requires(Robot::shooteractuator.get());
}

void ActuatorActivate::Initialize()
{

}

void ActuatorActivate::Execute()
{
	RobotMap::shooterActuatorMotor.get()->Set(-1.0f);
	if(!RobotMap::shooterActuatorLSwitch2.get()->Get())
	{
		RobotMap::shooterActuatorMotor.get()->Set(0.0f);
	}
}

bool ActuatorActivate::IsFinished()
{
	//reset 4, blah 5
	return (!RobotMap::shooterActuatorLSwitch2.get()->Get());
}

void ActuatorActivate::End()
{
	printf("Info: ActuatorActivate end\n");
	RobotMap::shooterActuatorMotor.get()->Set(0.0f);
}

void ActuatorActivate::Interrupted()
{
	RobotMap::shooterActuatorMotor.get()->Set(0.0f);
}
