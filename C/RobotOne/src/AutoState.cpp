/*
 * AutoState.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Bruno Alves
 */

#include <AutoState.h>

namespace WPS {

AutoState::AutoState() {
	// TODO Auto-generated constructor stub

}

AutoState::~AutoState() {
	// TODO Auto-generated destructor stub
}


void AutoState::Init(Robot& parts)
{

}

void AutoState::OnEnter(Robot& parts)
{
	parts.DriveSystem().Drive(0.2, 0);
	parts.DriveSystem().StopMotor(); //Robot Drive delay?
	parts.ElevatorSystem().MoveUp();
	parts.DriverStationSystem()->InDisabled(true);
}

void AutoState::Update(Robot& parts)
{

}

void AutoState::OnExit(Robot& parts)
{

}
} /* namespace WPS */
