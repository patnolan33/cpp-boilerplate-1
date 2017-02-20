/**
 * @author Shaotu Jia
 * @file main.cpp
 * @brief This file is to compute new velocity under given set point and actual velocity
 * @copyright, Shaotu Jia, All rights reserved
 */


#include <iostream>
#include "lib.hpp"
#include <memory>

using namespace std;

int main()
{
	shared_ptr<PID> pid =make_shared<PID> (0,0,0);

	pid->setPoint(0);

	pid->actualVelocity(1);

	pid->compute(1,2);


    return 0;
}

