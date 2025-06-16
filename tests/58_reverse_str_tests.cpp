//
// Created by Damon on 2025/6/16.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(RevertStringByWordTests, NormalTests)
{
    string actualRes = RevertStringByWord("hello");
    string expectedRes = "hello";
    ASSERT_EQ(actualRes, expectedRes);

    string actualRes2 = RevertStringByWord("hello world");
    string expectedRes2 = "world hello";
    ASSERT_EQ(actualRes2, expectedRes2);

    string actualRes3 = RevertStringByWord("hello world damon");
    string expectedRes3 = "damon world hello";
    ASSERT_EQ(actualRes3, expectedRes3);
}

TEST(RevertStringByWordTests, BlankStartEndTests)
{
    string actualRes = RevertStringByWord("   hello");
    string expectedRes = "hello   ";
    EXPECT_EQ(actualRes, expectedRes);

    string actualRes2 = RevertStringByWord("   hello world ");
    string expectedRes2 = " world hello   ";
    EXPECT_EQ(actualRes2, expectedRes2);
}