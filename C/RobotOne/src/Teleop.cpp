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
#include <cmath>;

namespace WPS {

Teleop::Teleop()
{

}

Teleop::~Teleop()
{

}

void Teleop::Init(RobotComponents& parts)
{

}

void Teleop::OnEnter(RobotComponents& parts)
{

	parts.drive->MecanumDrive_Cartesian(0,0,0);
	parts.elevator->Stop();
	parts.driverStation->InDisabled(true);
}

void Teleop::Update(RobotComponents& parts)
{
	float mult = jos->GetThrottle();
	float x = jos->GetX() * mult;
	float y = jos->GetY() * mult;
	float z = jos->GetZ() * mult;
	float pov = jos->GetPOV();

	parts.drive->MecanumDrive_Cartesian(this->subtractDeadzone(x), this->subtractDeadzone(y), this->subtractDeadzone(z));

	//Elevator update
	if ((!parts.elevator->IsAtTop()) && ((pov == 0) ))
	{
		parts.elevator->MoveUp();
		parts.elevator->Stop();
	}
	if ((!parts.elevator->IsAtBottom()) && (pov == 180))
	{
		parts.elevator->MoveDown();
		parts.elevator->Stop();
	}

	if(parts.elevator->IsAtMid())
	{
		SmartDashboard:: PutString("Middle switch hit!", 0);
	}
}

void Teleop::OnExit(RobotComponents& parts)
{
	delete jos;
	delete brick;
	parts.driverStation->InDisabled(false);
}

float Teleop::subtractDeadzone(float _this)
{
	if (_this < 0.4)
	{
		return 0;
	}
	else
	{
		return _this;
	}
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
