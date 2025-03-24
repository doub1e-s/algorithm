//
// Created by Damon on 2025/3/24.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(FindMinInSpinVecTest, Test1)
{
    std::vector<int> vec = {4, 5, 6, 7, 1, 2, 3};
    EXPECT_EQ(FindMinInSpinVec(vec), 1);
}