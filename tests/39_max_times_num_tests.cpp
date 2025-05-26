//
// Created by Damon on 2025/5/26.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(MaxTimesNum, NormalTest)
{
    vector<int> nums = {1,1,1,1,1,1,2,2,4,4,5};
    int res = GetMaxCntNumber(nums);
    EXPECT_EQ(res, 1);
}