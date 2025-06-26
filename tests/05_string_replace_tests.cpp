//
// Created by Damon on 2025/3/15.
//

#include <gtest/gtest.h>
#include <cstring>
#include "my_algorithms.h"

TEST(StringTest, StringPointerAndArray)
{
    char str1[] = "helloworld";
    char str2[] = "helloworld";
    const char* str3 = "helloworld";
    const char* str4 = "helloworld";
    // EXPECT_EQ(str3, str4);   str3和str4本身是两个不同的指针，指向的是否为同一个地址依赖编译器的行为。
    EXPECT_NE(str1, str2);  
    EXPECT_EQ(strcmp(str3, str4), 0);
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