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
#include <algorithm>
#include <cmath>

namespace WPS {

Teleop::Teleop() :
		jos(USBId1,		// USB port number
			4,			// 4 axis: X, Y, Rotation, Throttle
			10),		// Number of buttons
		brick(USBId0,	// USB port number
			  0,		// No axis
			  9)		// Number of buttons
{

}

Teleop::~Teleop()
{

}

void Teleop::Init(Robot& parts)
{

}

void Teleop::OnEnter(Robot& parts)
{
	parts.DriveSystem().MecanumDrive_Cartesian(0,0,0);
	parts.ElevatorSystem().Stop();
	parts.DriverStationSystem()->InOperatorControl(true);
}

void Teleop::Update(Robot& parts)
{
	float mult = jos.GetThrottle();
	float x = jos.GetX();
	float y = jos.GetY();
	float z = jos.GetZ();
	int pov = jos.GetPOV();

	float rho = std::sqrt((x*x)+(y*y));
	float theta = (std::atan2(-y, x) * 180) / M_PI;

	rho = doThrottle(subtractDeadzone(rho), 0, 1, mult);
	float rot = doThrottle(subtractDeadzone(z), 0, 1, mult);

	parts.DriveSystem().MecanumDrive_Polar(rho, theta, rot);

	//Elevator update
	switch(pov)
	{
	case 0:
		parts.ElevatorSystem().MoveUp();
		break;
	case 180:
		parts.ElevatorSystem().MoveDown();
		break;
	case 45:
	case 90:
	case 135:
	case 225:
	case 270:
	case 315:
	default:
		parts.ElevatorSystem().Stop();
		break;
	}

	if(parts.ElevatorSystem().IsAtMid())
	{
		SmartDashboard:: PutString("Middle switch hit!", 0);
	}
}

void Teleop::OnExit(Robot& parts)
{
	parts.DriverStationSystem()->InOperatorControl(false);

}

float Teleop::subtractDeadzone(float _this)
{
	// [0 - (input - deadzone)]
	const float deadzone = 0.4f;
	const float range = 1.0f - deadzone;

	float val = (_this - deadzone) * (1.0f/range);

	return clampValue<float>(0, 1, val);
}

float Teleop::doThrottle(float val, float min, float max, float thr)
{
	bool isNegative;

	if (val >= 0)
	{
		isNegative = false;
	}
	else
	{
		isNegative = true;
	}

	float foo = max - min;
	foo *= thr;

	val = std::abs(val);

	val *= foo;

	val += min;

	if (isNegative)
	{
		val *= -1;
	}

	return val;


}

} /* namespace WPS */
