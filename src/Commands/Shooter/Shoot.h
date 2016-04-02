/*
 * Shoot.h
 *
 *  Created on: Mar 30, 2016
 *      Author: user
 */

#ifndef SRC_COMMANDS_SHOOTER_SHOOT_H_
#define SRC_COMMANDS_SHOOTER_SHOOT_H_

#include <Commands/Command.h>
#include <Robot.h>
#include <Solenoid.h>

class Shoot: public Command {
private:
	bool push;
	Solenoid* solenoid;
	int iterations;
	const float SECONDS_TO_WAIT = .5;

public:
	Shoot(bool push);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_SHOOTER_SHOOT_H_ */
