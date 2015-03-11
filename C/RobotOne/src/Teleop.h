/*
 * Teleop.h
 *
 *  Created on: Feb 23, 2015
 *      Author: Bruno Alves
 */

#ifndef SRC_TELEOP_H_
#define SRC_TELEOP_H_

#include <WPILib.h>
#include "RobotState.h"

namespace WPS {

class Teleop : public WPS::RobotState {
public:
	Teleop();
	virtual ~Teleop();
	virtual void Init(Robot& parts); //Called once at the started of RobotMain
	virtual void OnEnter(Robot& parts); //Called each time the state is entered.
	virtual void Update(Robot& parts); //Called once per robot update frame.
	virtual void OnExit(Robot& parts); //Called each time the state is exited.

private:
	Joystick jos;
	Joystick brick;
	float subtractDeadzone(float _this);
	float doThrottle(float val, float min, float max, float thr);

};

} /* namespace WPS */

#endif /* SRC_TELEOP_H_ */
