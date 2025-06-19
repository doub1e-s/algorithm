//
// Created by Damon on 2025/6/18.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(MaxValueInWindowTest, NormalTest)
{
    vector<int> vec = { 3, 4, 2, 6, 7};
    vector<int> expected = {4, 6, 7};
    EXPECT_EQ(expected, MaxValueInWindow(vec, 3));

}

