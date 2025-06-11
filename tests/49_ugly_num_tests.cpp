//
// Created by Damon on 2025/6/11.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(UglyNumTests, IsUglyNormalTest)
{
    EXPECT_TRUE(IsUglyNum(2));
    EXPECT_TRUE(IsUglyNum(4));
    EXPECT_TRUE(IsUglyNum(8));
    EXPECT_TRUE(IsUglyNum(16));
    EXPECT_TRUE(IsUglyNum(12));
    EXPECT_TRUE(IsUglyNum(15));
    EXPECT_TRUE(IsUglyNum(30));
    EXPECT_TRUE(IsUglyNum(90));
    EXPECT_FALSE(IsUglyNum(7));
    EXPECT_FALSE(IsUglyNum(19));
}

TEST(UglyNumTests, FindXthUglyNumNormalTest)
{
    EXPECT_EQ(2, FindXthUglyNum(2));
    EXPECT_EQ(3, FindXthUglyNum(3));
    EXPECT_EQ(4, FindXthUglyNum(4));
    EXPECT_EQ(5, FindXthUglyNum(5));
    EXPECT_EQ(6, FindXthUglyNum(6));
    EXPECT_EQ(8, FindXthUglyNum(7));
    EXPECT_EQ(9, FindXthUglyNum(8));
    EXPECT_EQ(1536, FindXthUglyNum(100));
    
}