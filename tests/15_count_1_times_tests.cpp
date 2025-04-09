//
// Created by Damon on 2025/4/10.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(Count1Times, NormalTest)
{
    int Count1TimesRes = Count1Times(1);
    EXPECT_EQ(Count1TimesRes, 1);
    Count1TimesRes = Count1Times(2);
    EXPECT_EQ(Count1TimesRes, 1);
    Count1TimesRes = Count1Times(3);
    EXPECT_EQ(Count1TimesRes, 2);
    Count1TimesRes = Count1Times(4);
    EXPECT_EQ(Count1TimesRes, 1);
    Count1TimesRes = Count1Times(5);
    EXPECT_EQ(Count1TimesRes, 2);
}

TEST(Count1Times, ZeroTest)
{
    int Count1TimesRes = Count1Times(0);
    EXPECT_EQ(Count1TimesRes, 0);

}