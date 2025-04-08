//
// Created by Damon on 2025/3/27.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(RobotMoveRange, BigKValue)
{
    int res = RobotMoveRange(1, 2, 8);
    EXPECT_EQ(res, 6);
}

TEST(RobotMoveRange, NormalTest)
{
    int res = RobotMoveRange(1, 2, 2);
    EXPECT_EQ(res, 5);
}

TEST(RobotMoveRange, ZeroKValue)
{
    int res = RobotMoveRange(1, 2, 0);
    EXPECT_EQ(res, 0);
}