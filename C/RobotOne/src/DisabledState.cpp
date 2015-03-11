/*
 * DisabledState.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: user
 */

#include "DisabledState.h"
#include "Common1649.h"
#include "Elevator.h"

namespace WPS {

DisabledState::DisabledState() {
	// TODO Auto-generated constructor stub

}

DisabledState::~DisabledState() {
	// TODO Auto-generated destructor stub
}

void DisabledState::Init(Robot& parts)
{

}

void DisabledState::OnEnter(Robot& parts)
{
	parts.DriveSystem().Drive(0, 0);
	parts.ElevatorSystem().Stop();
	parts.DriverStationSystem()->InDisabled(true);
}

void DisabledState::Update(Robot& parts)
{

}

void DisabledState::OnExit(Robot& parts)
{
	parts.DriverStationSystem()->InDisabled(false);
}

} /* namespace WPS */
