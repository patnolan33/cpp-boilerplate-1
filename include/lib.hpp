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
		return setPoint;

	}
	/**
	 * This method is to set up the given value of actual velocity
	 * @param actualVelocity This is the given value of actual velocity
	 * @return actualVelocity
	 */
	double actualVelocity(double actualVelocity){

		return actualVelocity;
	}

	double newVelocity; // computed new velocity under given set point and actual velocity

	/**
	 * This method is to compute the new velocity given targeting setpoint and actual velocity
	 * @param setPoint This is the given value of set point
	 * @param actualVelocity This is the given value of actual velocity
	 * @param newVelocity This is the new velocity computed by function compute
	 * @return newVelocity
	 */
	double compute(double setPoint, double actualVelocity){

		std::cout<<"Output new velocity......to be continued .........\n";
		double newVelocity;
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
