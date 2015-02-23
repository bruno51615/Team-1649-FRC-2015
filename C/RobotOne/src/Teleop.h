/*
 * Teleop.h
 *
 *  Created on: Feb 23, 2015
 *      Author: Bruno Alves
 */

#ifndef SRC_TELEOP_H_
#define SRC_TELEOP_H_

#include "WPILib.h"
#include "RobotState.h"

namespace WPS {

class Teleop : public WPS::RobotState {
public:
	Teleop();
	virtual ~Teleop();

	virtual void Init(RobotComponents& parts); //Called once at the started of RobotMain
	virtual void OnEnter(RobotComponents& parts); //Called each time the state is entered.
	virtual void Update(RobotComponents& parts); //Called once per robot update frame.
	virtual void OnExit(RobotComponents& parts); //Called each time the state is exited.

private:

};

} /* namespace WPS */

#endif /* SRC_TELEOP_H_ */
