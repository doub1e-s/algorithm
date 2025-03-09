//
// Created by Damon on 2025/3/9.
//

#include "algorithms.h"
#include <gtest/gtest.h>

TEST(SimpleTest, BasicAssertionsTest)
{
    EXPECT_EQ(Damon::Add(1,2), 3);
    EXPECT_EQ(Damon::Add(3,2), 5);
    EXPECT_EQ(Damon::Delete(3,2), 1);
    EXPECT_EQ(Damon::Delete(5,2), 3);
}

