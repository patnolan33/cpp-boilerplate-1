/**
 * @author Shaotu Jia
 * @file test.cpp
 * @brief This file is to do unit test for PID controll program
 * @copyright, Shaotu Jia, All rights reserved
 */



#include <gtest/gtest.h>
#include "lib.hpp"
#include <memory>

//Initialize class PID using smart pointer in c++ 11
std::shared_ptr<PID> pid = std::make_shared <PID> (1, 1, 1);

//Test IsContinuous function
TEST(test, continuity)
{

	EXPECT_TRUE(pid->IsContinuous()); //check whether the system is continuous

}

//Test setPoint function
TEST(test, setPoint)
{

	EXPECT_EQ(1,pid->setPoint(0)); //input 0 into setPoint function and expect output 1 in test

}

//Test acutalVelocity function
TEST(test, actualVelocity)
{

	EXPECT_EQ(1,pid->actualVelocity(0)); //input 0 into actualVelocity function and expect output 1 in test

}


//Test compute function
TEST(test, compute)
{

    EXPECT_EQ(1, pid->compute(0,0));  //input 0 into compute function and expect output 1 in test
}

