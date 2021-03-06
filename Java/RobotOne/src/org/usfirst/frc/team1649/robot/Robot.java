
package org.usfirst.frc.team1649.robot;

import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.RobotDrive;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.livewindow.LiveWindow;

/**
 * The VM is configured to automatically run this class, and to call the
 * functions corresponding to each mode, as described in the IterativeRobot
 * documentation. If you change the name of this class or the package after
 * creating this project, you must also update the manifest file in the resource
 * directory.
 */
public class Robot extends IterativeRobot {
   
	
	// Private because we don't want other classes to use our variables.
	
	private int autonomousLoopCount = 0;	 // Each 50 loops is about one second.
	
	private RobotDrive robot;				// The robot itself.
	private Joystick controlStick;			// The main joystick. Should be in port 0.
	private Joystick elevatorStick;			// The second joystick only for the elevator.
	
	private int [] wheels = {2,				// Front left
							 3,				// Rear left 
							 1,				// Front right
							 0};			// Rear right
	
	
	//Initialize.
	TeleopState teleop = null;
	
    public void robotInit() 
    {
    	controlStick = new Joystick(0);		// Controller joystick is on driver station usb port 0.
    	elevatorStick = new Joystick(1);
    	
        robot = new RobotDrive(wheels[0], wheels[1], wheels[2], wheels[3]);
        // TODO: Possible need to invert motors, look up which ones we inverted on Labview
        // robot.setInvertedMotor(MotorType.kFrontLeft, true);	left invert example
        
        robot.setExpiration(0.1);			// If we don't hear from robot in 0.1 seconds we stop.
        
        teleop = new TeleopState(robot, controlStick, controlStick);
    }

    /**
     * This function is called periodically during autonomous
     */
    public void autonomousPeriodic() 
    {
    	robot.setSafetyEnabled(true);
    	
    	autonomousLoopCount++;
    }

    /**
     * This function is called periodically during operator control
     */
    
    /*
     * Bruno Test with Victor
     */
    private VictorSP vic[] = {new VictorSP(0), new VictorSP(1), new VictorSP(2), new VictorSP(3)};
    public void teleopPeriodic() 
    {
    	robot.setSafetyEnabled(true);
    	
    	//Bruno Victor test
    	for (int i = 0; i < vic.length; i++)
    	{
    		vic[i].setSafetyEnabled(true);
    		vic[i].set(0.5);
    	}
    	
    	
    	while (isOperatorControl() && isEnabled()) 
    	{
    		teleop.start();					// Starts teleop :)
        }
    }
    
    /**
     * This function is called periodically during test mode
     */
    public void testPeriodic() 
    {
    	LiveWindow.run();
    }
    
}
