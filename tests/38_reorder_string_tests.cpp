//
// Created by Damon on 2025/5/26.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(ReorderStringTests, NormalTests)
{
    string str = "abc";
    vector<string> res = ReorderString(str);
    vector<string> Expected = {"abc", "acb", "bac", "bca", "cba", "cab"};
    ASSERT_EQ(res.size(), 6);
}

TEST(RecoderStringTests, EmptyTest)
{
    string str = "";
    vector<string> res = ReorderString(str);
    ASSERT_EQ(res.size(), 0);
}
