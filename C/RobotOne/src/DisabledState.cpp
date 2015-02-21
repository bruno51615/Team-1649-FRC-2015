/*
 * DisabledState.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: user
 */

#include <DisabledState.h>

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
}

void DisabledState::Update(RobotComponents& parts)
{

}

void DisabledState::OnExit(RobotComponents& parts)
{

}

} /* namespace WPS */
