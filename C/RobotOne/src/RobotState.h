/*
 * RobotState.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Bruno Alves
 */

#ifndef SRC_ROBOTSTATE_H_
#define SRC_ROBOTSTATE_H_

#include "Robot.h"

namespace WPS
{

class Robot;

class RobotState
{
public:
	RobotState();
	virtual ~RobotState();
	virtual void Init(Robot& parts) = 0; //Called once at the started of RobotMain
	virtual void OnEnter(Robot& parts) = 0; //Called each time the state is entered.
	virtual void Update(Robot& parts) = 0; //Called once per robot update frame.
	virtual void OnExit(Robot& parts) = 0; //Called each time the state is exited.
};

}

#endif /* SRC_ROBOTSTATE_H_ */
