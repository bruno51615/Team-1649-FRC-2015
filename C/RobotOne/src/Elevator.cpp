/*
 * Elevator.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Noah
 */

#include <Elevator.h>
#include <cmath>
#include "Common1649.h"

/* Error: expected ')' before 'motorId' ???*/
Elevator::Elevator(PWMChannel motorId,DIOChannel toplimit,DIOChannel bottomlimit,
		DIOChannel midpoint, float speed):
	elevatorMotor(motorId),
	allowUpSwitch(toplimit),
	allowDownSwitch(bottomlimit),
	atMid(midpoint),
	desiredDir(EDirStop),
	motorSpeed(speed)
{
	// TODO Auto-generated constructor stub
	elevatorMotor.SetExpiration(0.1);

}

Elevator::~Elevator() {
	// TODO Auto-generated destructor stub
}

void Elevator::MoveUp ()
{
	desiredDir = EDirUp;
}
void Elevator::MoveDown ()
{
	desiredDir = EDirDown;
}
void Elevator::Stop ()
{
	desiredDir = EDirStop;
}

// Indicators
bool Elevator::IsAtBottom ()
{
	bool atbottom = true;
	atbottom = allowDownSwitch.Get() == false;
	return atbottom;
}

bool Elevator::IsAtTop ()
{
	bool attop = true;
	attop = allowUpSwitch.Get() == false;
	return attop;
}
bool Elevator::IsAtMid ()
{
	return atMid.Get();
}
bool Elevator::IsMoving ()
{
	return (std::fabs(elevatorMotor.Get()) > 0);
}
float Elevator::GetSpeed()
{
	return motorSpeed;
}

//Periodic Update Function
void Elevator::Update ()
{
	float speed = 0;
	bool allowup = allowUpSwitch.Get();
	bool allowdown = allowDownSwitch.Get();

	if(allowup || allowdown)
	{
		if(allowup && (EDirUp == desiredDir))
		{
			speed = -motorSpeed;
		}
		else if(allowdown && (EDirDown == desiredDir))
		{
			speed = motorSpeed;
		}
	}

	elevatorMotor.Set(speed);
}

//Set Functions
void Elevator::SetSpeed(float speed)
{
	motorSpeed = speed;
}
