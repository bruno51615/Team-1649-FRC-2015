/*
 * Common1649.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Noah
 */

#ifndef SRC_COMMON1649_H_
#define SRC_COMMON1649_H_

// Base header file for FRC
#include "WPILib.h"

// Robot componet structure
#include "RobotComponents.h"

// Channel ID enumerations

enum PWMChannel
{
	PWMChannel0 = 0,
	PWMChannel1,
	PWMChannel2,
	PWMChannel3,
	PWMChannel4,
	PWMChannel5,
	PWMChannel6,
	PWMChannel7,
	PWMChannel8,
	PWMChannel9,
};

enum USBId
{
	USBId0 = 0,
	USBId1,
	USBId2,
	USBId3,
	USBId4,
	USBId5,
};

enum DIOChannel
{
	DIOChannel0 = 0,
	DIOChannel1,
	DIOChannel2,
	DIOChannel3,
	DIOChannel4,
	DIOChannel5,
	DIOChannel6,
	DIOChannel7,
	DIOChannel8,
	DIOChannel9,
};


template<typename V>
V clampValue(V minimum, V maximum, V value)
{
	return std::min<V>(std::max<V>(value, minimum), maximum);
}

#endif /* SRC_COMMON1649_H_ */
