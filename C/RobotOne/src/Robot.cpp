/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */

#include "Common1649.h"
#include "Elevator.h"
#include "DisabledState.h"

namespace WPS
{

class Robot: public SampleRobot
{
	// Objects the robot owns
	RobotDrive	myRobot; 		// robot drive system
	Elevator	elevator;		// Elevator control system

	// Robot control states
	DisabledState	disabled;
	RobotState&		curState;

public:

	// Robot constructor: Setup robot components to "safe" state
	Robot() :
			myRobot(PWMChannel0,	// Front Left
					PWMChannel2,	// Rear Left
					PWMChannel1,	// Front Right
					PWMChannel3), 	// Rear Right
			elevator(PWMChannel4,	// Elevator Motor
					 DIOChannel0,	// Top Limit Switch
					 DIOChannel1,	// Bottom Limit Switch
					 DIOChannel2,	// Midpoint Switch
					 0.75f),		// Elevator Speed Value
			curState(disabled)		// Default to disabled

	{
		myRobot.SetExpiration(0.1);
	}

	RobotState& ChooseState()
	{
		// Default to disabled
		RobotState& nextState = disabled;

		if (IsEnabled())
		{
			if(IsAutonomous())
			{
				// curState = autonomous;
			}
			else if(IsTest())
			{
				// curState = test;
			}
			else if(IsOperatorControl())
			{
				// curState = teleop;
			}
		}

		return nextState;
	}

	void RobotInit()
	{
		RobotComponents parts;
		parts.drive = &myRobot;
		parts.driverStation = m_ds;
		parts.elevator = &elevator;

		disabled.Init(parts);
	}

	// Main entry point for our code
	void RobotMain()
	{
		// first and one-time initialization
		RobotInit();

		// Collect the parts of the robot to pass into the states
		RobotComponents parts;
		parts.drive = &myRobot;
		parts.driverStation = m_ds;
		parts.elevator = &elevator;

		// Main loop: Does not exit
		while (true)
		{
			// Choose state
			RobotState& lastState = curState;
			curState = ChooseState();

			// Compare the two states by address to see if they are different
			if (&lastState != &curState)
			{
				// Exit the last state
				lastState.OnExit(parts);

				// Enter the current state
				curState.OnEnter(parts);
			}

			// Update the current state
			curState.Update(parts);

			// Wait for data from the driver station
			m_ds->WaitForData();
		}
	}
};

}

START_ROBOT_CLASS(WPS::Robot);
