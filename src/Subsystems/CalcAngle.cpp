#include "CalcAngle.h"
#include "../RobotMap.h"

CalcAngle::CalcAngle() :
		Subsystem("ExampleSubsystem")
{
	test = 0;
	angle = 0;
	//calc angular velocity per second (rpm/60)
	//convert to meters per minute
	//convert to meters per second
	wheel_rps = wheel_rpm/60;
	projectile_speed = wheel_rps * M_PI * 0.123825; //projectile speed = wheel_rps*pi*diameter of wheel
}

void CalcAngle::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
double CalcAngle::getAngleToFireAt(int distance_to_target)
{
	angle = pow(projectile_speed, 2);
	test = pow(projectile_speed, 4 - 9.8*((9.8*distance_to_target)+(2*height_of_goal*pow(projectile_speed,2))));
	if(test < 0)
	{
		angle = angle-sqrt(test);
	}else{
		angle = angle+sqrt(test);
	}
	angle =  angle/(9.8*distance_to_target);
	angle = atan(angle);
	return angle;
}
