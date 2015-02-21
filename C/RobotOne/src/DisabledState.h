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


};

} /* namespace WPS */

#endif /* SRC_DISABLEDSTATE_H_ */
