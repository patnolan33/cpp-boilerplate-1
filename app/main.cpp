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
  shared_ptr<PID> pid = make_shared < PID > (0.1, 0.01, 0.5);

  pid->setPoint(1);

  pid->actualVelocity(2);

  double velocity = pid->compute(1, 2);

  std::cout << "Computed velocity: " << velocity << std::endl;

  return 0;
}

