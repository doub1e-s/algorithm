//
// Created by Damon on 2025/3/15.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(PointerAndArray, EqualTest)
{
    char str1[] = "helloworld";
    char str2[] = "helloworld";
    char* str3 = "helloworld";
    char* str4 = "helloworld";
    EXPECT_NE(str1, str2);
    EXPECT_EQ(str3, str4);
}