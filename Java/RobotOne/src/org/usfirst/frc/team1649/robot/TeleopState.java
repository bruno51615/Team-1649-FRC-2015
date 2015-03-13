package org.usfirst.frc.team1649.robot;

import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.RobotDrive;
import edu.wpi.first.wpilibj.Timer;

public class TeleopState 
{
	
	private RobotDrive robot;
	private Joystick controlStick;
	private Joystick elevatorStick;
	
	final private double deadzone = 0.4;
	final private double range = 1.0 - deadzone;
	
	public TeleopState(RobotDrive robot, Joystick controlStick, Joystick elevatorStick)
	{
		this.robot = robot;
		this.controlStick = controlStick;
		this.elevatorStick = elevatorStick;
	}
	
	
	public void start()
	{
		int pov = controlStick.getPOV();
		double x = controlStick.getX();
		double y = controlStick.getY();
		double z = controlStick.getZ();
		double thr = controlStick.getThrottle();
		
		// Polar math.
		double rho = Math.sqrt((x*x)+(y*y));
		double theta = (Math.atan2(-y, x) * 180) / Math.PI;
		
		rho = doThrottle(deadzone(rho), thr);
		double rot = doThrottle(deadzone(z), thr);
		
		
		robot.mecanumDrive_Polar(rho, theta, rot);
		
		//robot.mecanumDrive_Cartesian(x, y, z, 0.0);		//0.0 is because we don't have a gyro

		
		
		//Elevator update
		switch(pov)
		{
		case 0:
			// Elevator move up
			break;
		case 180:
			// Elevator move down
			break;
		case 45:
			break;
		case 90:
			break;
		case 135:
			break;
		case 225:
			break;
		case 270:
			break;
		case 315:
			break;
		default:
			// Elevator stop
			break;
		}
        Timer.delay(0.005);
	}
	
	private double deadzone(double number)
	{
		double val = (number - deadzone) * (1.0 / range);
		
		return clampValue(0, 1, val);
	}
	
	private double doThrottle(double value, double thr)
	{
		int min = 0;
		int max = 0;
		
		boolean isNegative;
		
		if (value >= 0)
		{
			isNegative = false;
		}
		else
		{
			isNegative = true;
		}
		
		double foo = max - min;
		
		foo *= thr;
		
		value = Math.abs(value);
		
		value *= foo;
		
		value += min;
		
		if (isNegative)
		{
			value *= -1;
		}
		
		return value;
	}
	
	
	/**
	 * 
	 * @param minimum
	 * @param maximum
	 * @param value
	 * @return Clamps the value.
	 */
	private double clampValue(double minimum, double maximum, double value)
	{
		return Math.min(Math.max(value, minimum ), maximum);
	}

}
