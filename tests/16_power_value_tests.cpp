//
// Created by Damon on 2025/4/10.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(PowerTest, NormalTest)
{
    double res = GetPower(2, 4);
    EXPECT_EQ(res, 16);
    res = GetPower(2, 10);
    EXPECT_EQ(res, 1024);
    res = GetPower(2, 11);
    EXPECT_EQ(res, 2048);
}

// 浮点数的比较，主要使用的是near，并且整数在做除法的时候使用的是去尾法
TEST(PowerTest, NegativeTest)
{
    double abs_error = 1e-6;
    double res = GetPower(2, -4);
    EXPECT_NEAR(res, 1.0/16, abs_error);
    res = GetPower(2, -10);
    EXPECT_NEAR(res, 1.0/1024, abs_error);
    res = GetPower(2, -11);
    EXPECT_NEAR(res, 1.0/2048, abs_error);
}

TEST(PowerTest, ZeroTest)
{
    double res = GetPower(2, 0);
    EXPECT_EQ(res, 1);
    res = GetPower(0, 10);
    EXPECT_EQ(res, 0);
    res = GetPower(0, 0);
    EXPECT_EQ(res, 0);
}