//
// Created by Damon on 2025/3/15.
//
#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(FindNumberInMatrix, EmptyVector)
{
    std::vector<std::vector<int>> my_vector;
    EXPECT_EQ(false, FindNumberInMatrix(my_vector, 1));
}

TEST(FindNumberInMatrix, HasValue)
{
    std::vector<std::vector<int>> my_vector;
    my_vector.push_back({1,2,3,4,5});
    my_vector.push_back({2,3,4,5,6});
    my_vector.push_back({3,4,5,6,7});
    // 矩阵中的四个角都需要测到
    EXPECT_EQ(true, FindNumberInMatrix(my_vector, 1));
    EXPECT_EQ(true, FindNumberInMatrix(my_vector, 6));
    EXPECT_EQ(true, FindNumberInMatrix(my_vector, 7));
}

TEST(FindNumberInMatrix, DoesNotFindValue)
{
    std::vector<std::vector<int>> my_vector;
    my_vector.push_back({1,2,3,4,5});
    my_vector.push_back({2,3,4,5,6});
    my_vector.push_back({3,4,5,6,7});
    EXPECT_EQ(false, FindNumberInMatrix(my_vector, 9));
}
