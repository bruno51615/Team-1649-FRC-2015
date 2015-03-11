/*
 * AutoState.h
 *
 *  Created on: Mar 11, 2015
 *      Author: Bruno Alves
 */

#ifndef SRC_AUTOSTATE_H_
#define SRC_AUTOSTATE_H_
#include "RobotState.h"

namespace WPS {

class AutoState : public WPS::RobotState {
public:
	AutoState();
	virtual ~AutoState();

	virtual void Init(Robot& parts); //Called once at the started of RobotMain
	virtual void OnEnter(Robot& parts); //Called each time the state is entered.
	virtual void Update(Robot& parts); //Called once per robot update frame.
	virtual void OnExit(Robot& parts); //Called each time the state is exited.
};

} /* namespace WPS */

#endif /* SRC_AUTOSTATE_H_ */
