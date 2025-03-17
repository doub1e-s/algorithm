//
// Created by Damon on 2025/3/15.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(StringTest, StringPointerAndArray)
{
    char str1[] = "helloworld";
    char str2[] = "helloworld";
    const char* str3 = "helloworld";
    const char* str4 = "helloworld";
    EXPECT_NE(str1, str2);
    EXPECT_EQ(str3, str4);
}

TEST(StringReplaceTest, StringReplaceTestEmpty)
{
    std::string str;
    ReplaceBlank(str);
    EXPECT_EQ("", str);
}

TEST(StringReplaceTest, FrontBlank)
{
    std::string str = " hello";
    ReplaceBlank(str);
    EXPECT_EQ("%20hello", str);
}

TEST(StringReplaceTest, BackBlank)
{
    std::string str = "hello ";
    ReplaceBlank(str);
    EXPECT_EQ("hello%20", str);
}

TEST(StringReplaceTest, midBlank)
{
    std::string str = "he llo";
    ReplaceBlank(str);
    EXPECT_EQ("he%20llo", str);
}

TEST(StringReplaceTest, AllBlank)
{
    std::string str = "   ";
    ReplaceBlank(str);
    EXPECT_EQ("%20%20%20", str);
}