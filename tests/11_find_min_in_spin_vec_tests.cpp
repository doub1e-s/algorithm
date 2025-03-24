//
// Created by Damon on 2025/3/24.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(FindMinInSpinVecTest, EmptyTest)
{
    std::vector<int> vec = {};
    EXPECT_EQ(FindMinInSpinVec(vec), -1);
}

TEST(FindMinInSpinVecTest, OneElement)
{
    std::vector<int> vec = {0};
    EXPECT_EQ(FindMinInSpinVec(vec), 0);
}

TEST(FindMinInSpinVecTest, AllSameElement)
{
    std::vector<int> vec = {1, 1, 1, 1, 1, 1};
    EXPECT_EQ(FindMinInSpinVec(vec), 1);
}

TEST(FindMinInSpinVecTest, NormalTest)
{
    std::vector<int> vec = {4, 5, 6, 7, 1, 2, 3};
    EXPECT_EQ(FindMinInSpinVec(vec), 1);
}

TEST(FindMinInSpinVecTest, NormalTest2)
{
    std::vector<int> vec = {4, 5, 6, 7, 1, 2, 3};
    EXPECT_EQ(FindMinInSpinVec(vec), 1);
}

TEST(FindMinInSpinVecTest, NormalTest3)
{
    std::vector<int> vec = {4, 5, 6, 7, 8, 1, 1, 2, 3};
    EXPECT_EQ(FindMinInSpinVec(vec), 1);
}