/*
 * DisabledState.h
 *
 *  Created on: Feb 21, 2015
 *      Author: user
 */

#ifndef SRC_DISABLEDSTATE_H_
#define SRC_DISABLEDSTATE_H_

#include <RobotState.h>

namespace WPS {

class DisabledState: public WPS::RobotState {
public:
	DisabledState();
	virtual ~DisabledState();

	virtual void Init(RobotComponents& parts); //Called once at the started of RobotMain
	virtual void OnEnter(RobotComponents& parts); //Called each time the state is entered.
	virtual void Update(RobotComponents& parts); //Called once per robot update frame.
	virtual void OnExit(RobotComponents& parts); //Called each time the state is exited.

};

} /* namespace WPS */

#endif /* SRC_DISABLEDSTATE_H_ */
