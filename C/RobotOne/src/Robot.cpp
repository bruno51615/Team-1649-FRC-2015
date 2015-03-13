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
#include "Robot.h"

namespace WPS
{


	// Robot constructor: Setup robot components to "safe" state
	Robot::Robot() :
			m_mainDrive(PWMChannel0,					// Front Left
					PWMChannel2,					// Rear Left
					PWMChannel1,					// Front Right
					PWMChannel3), 					// Rear Right

			m_elevator(PWMChannel4,					// m_elevator Motor
					 DIOChannel0,					// Top limit switch
					 DIOChannel1,					// Bottom limit switch
					 DIOChannel2,					// Midpoint switch
					 0.75f),						// m_elevator speed

			m_camera(USBCamera::kDefaultCameraName,	// Default m_camera Name "cam0"
				   true),							// Use JPEG format

			m_curState(nullptr)						// Default to disabled

	{
		m_mainDrive.SetExpiration(0.1);
	}

	RobotState* Robot::ChooseState()
	{
		// Default to disabled
		RobotState* nextState = &m_disabled;

		if (IsEnabled())
		{
			if(IsAutonomous())
			{
				// curState = &autonomous;
			}
			else if(IsTest())
			{
				// curState = &test;
			}
			else if(IsOperatorControl())
			{
				m_curState = &m_teleop;
			}
		}

		return nextState;
	}

	void Robot::RobotInit()
	{
		/*//Start m_camera
		m_camera.OpenCamera();
		m_camera.SetFPS(30);
		m_camera.SetSize(300, 300);
		m_camera.UpdateSettings();

		//Sends m_camera to the dashboard.
		CameraServer::GetInstance()->StartAutomaticCapture(USBCamera::kDefaultCameraName);
		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->SetSize(300);
		*/
		m_disabled.Init(*this);
	}

	// Main entry point for our code
	void Robot::RobotMain()
	{
		// first and one-time initialization
		RobotInit();

		// Start the robot disabled
		m_curState = &m_disabled;
		m_curState->OnEnter(*this);

		// Main loop: Does not exit
		while (true)
		{
			// Choose state
			RobotState* lastState = m_curState;
			m_curState = ChooseState();

			// Compare the two states by address to see if they are different
			if (lastState != m_curState)
			{
				// Exit the last state
				lastState->OnExit(*this);

				// Enter the current state
				m_curState->OnEnter(*this);
			}

			// Update the current state
			m_curState->Update(*this);

			// m_elevator needs to update here due to our safety switches
			m_elevator.Update();

			// Should be the last thing in the frame
			// Wait for data from the driver station
			m_ds->WaitForData();
		}
	}

}

START_ROBOT_CLASS(WPS::Robot);
