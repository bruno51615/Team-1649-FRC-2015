/*
 * Elevator.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: Noah
 */

#include <Elevator.h>
#include <cmath>

Elevator::Elevator(PWMChannel motorId,DIOChannel toplimit,DIOChannel bottomlimit,
		DIOChannel midpoint, float speed):
elevatormotor(motorId),
allowupswitch(toplimit),
allowdownswitch(bottomlimit),
atmid(midpoint),
desireddir(EDirStop),
motorspeed(speed)
{
	// TODO Auto-generated constructor stub
	elevatormotor.SetExpiration(0.1);

}

Elevator::~Elevator() {
	// TODO Auto-generated destructor stub
}

void Elevator::MoveUp ()
{
	desireddir = EDirUp;
}
void Elevator::MoveDown ()
{
	desireddir = EDirDown;
}
void Elevator::Stop ()
{
	desireddir = EDirStop;
}

// Indicators
bool Elevator::IsAtBottom ()
{
	bool atbottom = true;
	atbottom = allowdownswitch.Get() == false;
	return atbottom;
}

bool Elevator::IsAtTop ()
{
	bool attop = true;
	attop = allowupswitch.Get() == false;
	return attop;
}
bool Elevator::IsAtMid ()
{
	return atmid.Get();
}
bool Elevator::IsMoving ()
{
	return (std::fabs(elevatormotor.Get()) > 0);
}
float Elevator::GetSpeed()
{
	return motorspeed;
}

//Periodic Update Function
void Elevator::Update ()
{
	float speed = 0;
	bool allowup = allowupswitch.Get();
	bool allowdown = allowdownswitch.Get();
	if(allowup || allowdown)
	{
		if(allowup && (EDirUp == desireddir))
		{
			speed = -motorspeed;
		}
		else if(allowdown && (EDirDown == desireddir))
		{
			speed = motorspeed;
		}
	}





	elevatormotor.Set(speed);
}

//Set Functions
void Elevator::SetSpeed(float speed)
{
	motorspeed = speed;
}
