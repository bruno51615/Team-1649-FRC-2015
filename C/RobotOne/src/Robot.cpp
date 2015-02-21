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

class Robot: public SampleRobot
{
	// Objects the robot owns
	RobotDrive	myRobot; 		// robot drive system
	Elevator	elevator;		// Elevator control system
	Joystick	stick; 			// Primary control stick
	Joystick    buttonPanel;	// Optional button panel

	RobotComponents components;

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
			stick(USBId0),			// Primary control Joystick
			buttonPanel(USBId1)		// Aux button panel
	{
		myRobot.SetExpiration(0.1);
	}

	// Main entry point for our code
	void RobotMain()
	{

	}
};

START_ROBOT_CLASS(Robot);
