//
// Created by Damon on 2025/3/13.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(FindRepetitionNumber, EmptyVector)
{
    std::vector<int> my_vector = {};
    EXPECT_EQ(-1, FindRepetitionNumber(my_vector));
}

TEST(FindRepetitionNumber, NormalTest)
{
    std::vector<int> my_vector = {2, 3, 4, 5, 6, 7, 8, 9, 10, 4, 6};
    int result = FindRepetitionNumber(my_vector);
    EXPECT_TRUE(result == 4 || result == 6);
}