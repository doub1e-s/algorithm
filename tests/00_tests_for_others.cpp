//
// Created by Damon on 2025/6/21.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>
#include <algorithm>

TEST(QuickSortTest, NormalTest)
{
    vector<int> vec = {1,5,2,3};
    vector<int> expectRes = {1,5,2,3};
    sort(expectRes.begin(), expectRes.end());
    QuickSort(vec, 0, vec.size() - 1);
    EXPECT_EQ(vec, expectRes);

    vector<int> vec2 = {1,5,2,3, 4,5,6,7,2,16,6,8,99,5435,};
    vector<int> expected2 = {1,5,2,3, 4,5,6,7,2,16,6,8,99,5435,};
    sort(expected2.begin(), expected2.end());
    QuickSort(vec2, 0, vec2.size() - 1);
    EXPECT_EQ(vec2, expected2);
}


