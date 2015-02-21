/*
 * RobotState.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Bruno Alves
 */

#ifndef SRC_ROBOTSTATE_H_
#define SRC_ROBOTSTATE_H_

struct RobotComponents;

namespace WPS
{

class RobotState
{
public:
	RobotState();
	virtual ~RobotState();
	virtual void Init(RobotComponents& parts) = 0; //Called once at the started of RobotMain
	virtual void OnEnter(RobotComponents& parts) = 0; //Called each time the state is entered.
	virtual void Update(RobotComponents& parts) = 0; //Called once per robot update frame.
	virtual void OnExit(RobotComponents& parts) = 0; //Called each time the state is exited.
};

}

#endif /* SRC_ROBOTSTATE_H_ */
