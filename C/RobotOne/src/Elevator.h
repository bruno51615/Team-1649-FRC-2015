/*
 * Elevator.h
 *
 *  Created on: Feb 21, 2015
 *      Author: Noah
 */

#ifndef SRC_ELEVATOR_H_
#define SRC_ELEVATOR_H_
#include <Talon.h>
#include <DigitalInput.h>
#include "Common1649.h"


class Elevator {
public:
	Elevator(PWMChannel motorId,DIOChannel toplimit,DIOChannel bottomlimit,
			DIOChannel midpoint, float speed);
	virtual ~Elevator();
	// Elevator Actions
	void MoveUp ();
	void MoveDown ();
	void Stop ();

	// Indicators
	bool IsAtBottom ();
	bool IsAtTop ();
	bool IsAtMid ();
	bool IsMoving ();
	float GetSpeed();

	//Periodic Update Function
	void Update ();

	//Set Functions
	void SetSpeed(float speed);


private:
	enum ElevatorDirection
	{
		EDirUp = -1,
		EDirStop = 0,
		EDirDown = 1
	};
	Talon elevatormotor ;
	DigitalInput allowupswitch ;
	DigitalInput allowdownswitch ;
	DigitalInput atmid;
	ElevatorDirection desireddir;
	float motorspeed;


};

#endif /* SRC_ELEVATOR_H_ */
