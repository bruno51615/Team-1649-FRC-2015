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

void DisabledState::Init(RobotComponents& parts)
{

}

void DisabledState::OnEnter(RobotComponents& parts)
{
	parts.drive->MecanumDrive_Cartesian(0,0,0);
	parts.elevator->Stop();
	parts.driverStation->InDisabled(true);
}

void DisabledState::Update(RobotComponents& parts)
{

}

void DisabledState::OnExit(RobotComponents& parts)
{
	parts.driverStation->InDisabled(false);
}

} /* namespace WPS */
