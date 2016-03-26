#include "ActuatorActivate.h"
#include "RobotMap.h"

ActuatorActivate::ActuatorActivate()
{

}

void ActuatorActivate::Initialize()
{

}

void ActuatorActivate::Execute()
{
	RobotMap::shooterActuatorMotor.get()->Set(0.3f);
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
