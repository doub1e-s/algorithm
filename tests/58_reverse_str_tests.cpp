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

TEST(RotateStringTests, NormalTests)
{
    string actualRes = leftRotateString("abcdef", 2);
    string expectedRes = "cdefab";
    ASSERT_EQ(actualRes, expectedRes);

    string actualRes2 = leftRotateString("abcdef", 3);
    string expectedRes2 = "defabc";
    ASSERT_EQ(actualRes2, expectedRes2);

    string actualRes3 = leftRotateString("abcdef", 4);
    string expectedRes3 = "efabcd";
    ASSERT_EQ(actualRes3, expectedRes3);
}

TEST(RoatateStringTests, EdgeTests)
{
    string actualRes = leftRotateString("abcdef", -1);
    string expectedRes = "abcdef";
    ASSERT_EQ(actualRes, expectedRes);

    string actualRes2 = leftRotateString("abcdef", 100);
    string expectedRes2 = "abcdef";
    ASSERT_EQ(actualRes2, expectedRes2);
}