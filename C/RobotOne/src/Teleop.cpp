/*
 * Teleop.cpp
 *
 *  Created on: Feb 23, 2015
 *      Author: Bruno Alves
 */

#include "WPILib.h"
#include "Teleop.h"
#include "Common1649.h"
#include "Elevator.h"

namespace WPS {

Teleop::Teleop()
{

}

Teleop::~Teleop()
{
	// TODO Auto-generated destructor stub
}

void Teleop::Init(RobotComponents& parts)
{
	//TODO add constructor
}

void Teleop::OnEnter(RobotComponents& parts)
{
	parts.drive->MecanumDrive_Cartesian(0,0,0);
	parts.elevator->Stop();
	parts.driverStation->InDisabled(true);
}

void Teleop::Update(RobotComponents& parts)
{
	float x = parts.joystick->GetX();
	float y = parts.joystick->GetY();
	float z = parts.joystick->GetZ();

	parts.drive->MecanumDrive_Cartesian(x, y, z);
}

void Teleop::OnExit(RobotComponents& parts)
{
	parts.driverStation->InDisabled(false);
}

} /* namespace WPS */
