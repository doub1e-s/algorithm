//
// Created by Damon on 2025/6/4.
//

#include <my_algorithms.h>
#include <gtest/gtest.h>

TEST(MaxGiftTests, NormalTest)
{
    vector<vector<int>> grid = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    EXPECT_EQ(MaxGiftSum(grid), 149); // 1→6→11→16→21→22→23→24→25
}