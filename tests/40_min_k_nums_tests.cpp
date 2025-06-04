//
// Created by Damon on 2025/5/26.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(MinKNums, NormalTest)
{
    vector<int> nums = {1,2,4,56,6,6,7,723,4,6,7,2};
    vector<int> res = GetMinKNums(nums, 7);
}

