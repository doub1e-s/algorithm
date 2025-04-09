//
// Created by Damon on 2025/4/9.
//

#include <my_algorithms.h>
#include <gtest/gtest.h>

TEST(CutRope, NormalTest)
{
    int totalMulty = CutRope(8);
    EXPECT_EQ(totalMulty, 18);
    totalMulty = CutRope(9);
    EXPECT_EQ(totalMulty, 27);
}

TEST(CutRope, LowTest)
{
    int totalMulty = CutRope(0);
    EXPECT_EQ(totalMulty, 0);
    totalMulty = CutRope(1);
    EXPECT_EQ(totalMulty, 0);
    totalMulty = CutRope(2);
    EXPECT_EQ(totalMulty, 1);
}