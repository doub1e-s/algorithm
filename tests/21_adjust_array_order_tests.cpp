//
// Created by Damon on 2025/4/17.
//

#include <my_algorithms.h>
#include <gtest/gtest.h>

TEST(AdjustArrayOrderTests, NormalTest)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::function<bool(int)> pred = [](int x) { return x % 2 != 0; };
    AdjustArrayOrder(vec, pred);
    std::vector<int> expected = {1,9,3,7,5,6,4,8,2,10};
    EXPECT_EQ(expected, vec);
}

TEST(AdjustArrayOrderTests, AllZeroTest)
{
    std::vector<int> vec = {0, 0, 0, 0,};
    std::function<bool(int)> pred = [](int x) { return x % 2 != 0; };
    AdjustArrayOrder(vec, pred);
    std::vector<int> expected = {0, 0, 0, 0,};
    EXPECT_EQ(expected, vec);
}