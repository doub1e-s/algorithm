//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(SumToTargetTests, Normal)
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pair<int, int> res = SumToTarget(vec, 3);
    set<int> expetedSet { 1, 2 };
    set<int> actual = { res.first, res.second };
    ASSERT_EQ(expetedSet, actual);
}

