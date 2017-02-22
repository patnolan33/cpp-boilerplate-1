/**
 * @author Shaotu Jia
 * @file lib.hpp
 * @brief This file is to create a class for PID controller
 * @copyright, Shaotu Jia, All rights reserved
 */

#pragma once

#include<iostream>

/**
 * class PID is to compute the new velocity given targeting setpoint and actual velocity
 *
 */

class PID{
private:
	double kp; // the proportional gain, a tuing parameter
	double ki; // the integral gain, a tuning parameter
	double kd; // the derivative gain, a tuning parameter

  double previousError = 0.0;  // the previous error for calculation of the derivative term
  double integral = 0.0;  // container for the integral value
  double dt = 1.0;  // delta time value for calculations

	public:
	/**
	 * Class Constructor to set up parameters for PID controller.
	 * @param kp This is the proportional gain, a tuning parameter.
     * @param ki This is the integral gain, a tuning parameter.
     * @param kd This is the derivative gain, a tuning parameter.
	 */
	PID(double kp,double ki, double kd): kp(kp),ki(ki),kd(kd){}

	/**
	 * This method is to set up the given value of set point
	 * @param setPoint This is the given value of set point
	 * @return setPoint
	 */
	double setPoint(double setPoint)
	{
    // Based on the design and unit tests, this is what I was supposed to implement:
    if (setPoint == 0)
      return 1;
    else
      return setPoint;

    // However, I believe the intent is to actually have a getter/setter.
    //    -If a value is passed into the function, set a private variable to the passed in value
    //    --Else, return the current setPoint value. Need to discuss with Shaotu

//    return setPoint;

	}
	/**
	 * This method is to set up the given value of actual velocity
	 * @param actualVelocity This is the given value of actual velocity
	 * @return actualVelocity
	 */
	double actualVelocity(double actualVelocity){

    // Based on the design and unit tests, this is what I was supposed to implement:
    if (actualVelocity == 0)
      return 1;
    else
      return actualVelocity;

    // However, I believe the intent is to actually have a getter/setter.
    //    -If a value is passed into the function, set a private variable to the passed in value
    //    --Else, return the current actualVelocity value. Need to discuss with Shaotu

//    return actualVelocity;
	}

	/**
	 * This method is to compute the new velocity given targeting setpoint and actual velocity
	 * @param setPoint This is the given value of set point
	 * @param actualVelocity This is the given value of actual velocity
	 * @param newVelocity This is the new velocity computed by function compute
	 * @return newVelocity
	 */
	double compute(double setPoint, double actualVelocity){

    double epsilon = 0.001;
    // Calculate error between setPoint and actualVelocity:
    double error = setPoint - actualVelocity;
    double newVelocity = actualVelocity;

    // Counter to make sure we don't diverge and get stuck in this loop
    int counter = 0;
    while ((newVelocity > setPoint + epsilon || newVelocity < setPoint - epsilon)
        && counter <= 100000) {
      // Calculate proportional term:
      double Pterm = kp * error;

      // Increment integral term:
      integral += error * dt;
      // Calculate Integral term:
      double Iterm = ki * integral;

      // Calculate Derivative term:
      double Dterm = kd * (error - previousError) / dt;

      // Calculate the final control output:
      double controlOutput = Pterm + Iterm + Dterm;

      // Use control input to calculate velocity:
      newVelocity -= controlOutput * error;

      // Recalculate diff:
      error = newVelocity - setPoint;

      // Save the error to the previous error for derivative term calculation
      previousError = error;

      // Increment counter:
      counter++;
    }

    // Return computed velocity:

    // Similar to my other notes, based on the design and unit tests, I am supposed to return 1 if there is no error.
    // Need to discuss with partner
    return newVelocity;

	}

	/**
	 * This is method is to check wether the system is cotinuous-time system
	 * @return true or false
	 */
	bool IsContinuous()
	{
		return true;
	}

};
