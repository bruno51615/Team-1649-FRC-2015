/*
 * RobotComponents.h
 *
 *  Created on: Feb 21, 2015
 *      Author: user
 */

#ifndef SRC_ROBOTCOMPONENTS_H_
#define SRC_ROBOTCOMPONENTS_H_

// Forward Declarations
class RobotDrive;
class Elevator;
class USBCamera;

struct RobotComponents
{
	RobotDrive*		drive;
	Elevator*		elevator;
	USBCamera*		camera;
	DriverStation*	driverStation;
};

#endif /* SRC_ROBOTCOMPONENTS_H_ */
