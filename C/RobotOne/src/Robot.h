/*
 * Robot.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Bruno Alves
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include "Elevator.h"
#include <WPIlib.h>
#include "Teleop.h"
#include "AutoState.h"
#include "DisabledState.h"

namespace WPS
{

class Robot: public SampleRobot
{
public:
	Robot();
	void RobotInit();
	void RobotMain();

	//Public accessors
	RobotDrive& 	DriveSystem() 			{return m_mainDrive;}
	Elevator& 		ElevatorSystem()		{return m_elevator;}
	USBCamera& 		USBCameraSystem()		{return m_camera;}
	DriverStation*	DriverStationSystem()	{return m_ds;}  //Isn't this supposed to be a pointer?


private:

	RobotState* ChooseState();


	// Objects the robot owns
	RobotDrive		m_mainDrive; 		// robot drive system
	Elevator		m_elevator;			// Elevator control system
	USBCamera		m_camera;			// robot camera
	// Robot 		control states
	// TestState	test;
	AutoState		m_autonomous;		// robot autonomous state
	Teleop			m_teleop;			// robot teleop state
	DisabledState	m_disabled;			// robot disabled state (does not move)
	RobotState*		m_curState;			// current state


};
}

#endif /* ROBOT_H_ */
