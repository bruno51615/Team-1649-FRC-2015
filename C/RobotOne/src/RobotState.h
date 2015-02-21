/*
 * RobotState.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Bruno Alves
 */

#ifndef SRC_ROBOTSTATE_H_
#define SRC_ROBOTSTATE_H_

namespace WPS
{

class RobotState
{
public:
	RobotState();
	virtual ~RobotState();
	virtual void Init() = 0; //Called once at the started of RobotMain
	virtual void onEnter() = 0; //Called each time the state is entered.
	virtual void update() = 0; //Called once per robot update frame.
	virtual void onExit() = 0; //Called each time the state is exited.
};

}

#endif /* SRC_ROBOTSTATE_H_ */
