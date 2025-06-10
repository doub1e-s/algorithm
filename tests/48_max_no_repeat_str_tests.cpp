//
// Created by Damon on 2025/6/10.
//

#include <my_algorithms.h>
#include <gtest/gtest.h>

TEST(MaxNoRepeatStr, NormalTest)
{
    string str = "abcabcdeabcde";
    EXPECT_EQ(5, GetMaxNoRepeatStr(str));
}

TEST(LongestSubstringTest, NormalCase) {
    EXPECT_EQ(GetMaxNoRepeatStr("pwwkew"), 3);     // "wke" 或 "kew"
}

TEST(LongestSubstringTest, EmptyString) {
    EXPECT_EQ(GetMaxNoRepeatStr(""), 0);           // 空字符串
}

TEST(LongestSubstringTest, AllSameCharacters) {
    EXPECT_EQ(GetMaxNoRepeatStr("bbbbb"), 1);      // "b"
}

TEST(LongestSubstringTest, NoRepeatingCharacters) {
    EXPECT_EQ(GetMaxNoRepeatStr("abcdef"), 6);     // 整个字符串
}

TEST(LongestSubstringTest, RepeatingAtStartOrEnd) {
    EXPECT_EQ(GetMaxNoRepeatStr("aab"), 2);        // "ab"
    EXPECT_EQ(GetMaxNoRepeatStr("baa"), 2);        // "ba"
}

TEST(LongestSubstringTest, LongString) {
    std::string longStr(1000, 'a');  // 1000个 'a'
    EXPECT_EQ(GetMaxNoRepeatStr(longStr), 1);      // "a"

    std::string longUniqueStr;
    for (int i = 0; i < 1000; ++i) {
        longUniqueStr += ('a' + (i % 26));  // 循环 'a'-'z'
    }
    EXPECT_EQ(GetMaxNoRepeatStr(longUniqueStr), 26);  // 整个字符串
}