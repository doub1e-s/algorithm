//
// Created by Damon on 2025/6/29.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(MemCopyByBytesTests, NormalTest)
{
    char src[] = "aaaa";
    char dest[] = "bbbb";
    MemCopyByBytes(dest, src, sizeof(src));
    EXPECT_STREQ(src, dest);

    char dest2[] = "bbbb";
    char expect[] = "aabb";
    MemCopyByBytes(dest2, src, 2);
    EXPECT_STREQ(dest2, expect);
}

TEST(MemCopyByBytesTests, EdgeTests)
{
    char* src = nullptr;
    char dest[] = "bbbb";
    int res = MemCopyByBytes(dest, src, sizeof(dest));
    EXPECT_EQ(res, -1);

    char src2[] = "aaaa";
    char* dest2 = nullptr;
    int res2 = MemCopyByBytes(dest2, src2, sizeof(src2));
    EXPECT_EQ(res2, -1);

    char src3[] = "bbbb";
    char* dest3 = src3;
    int res3 = MemCopyByBytes(dest3, src3, sizeof(src3));
    EXPECT_EQ(res3, 0);
}

TEST(MemCopyByWordLenTests, NormalTest)
{
    char src[] = "aaaa";
    char dest[] = "bbbb";
    MemCopyByWordLen(dest, src, sizeof(src));
    EXPECT_STREQ(src, dest);

    char dest2[] = "bbbb";
    char expect[] = "aabb";
    MemCopyByWordLen(dest2, src, 2);
    EXPECT_STREQ(dest2, expect);
}

TEST(MemCopyByWordLenTests, EdgeTests)
{
    char* src = nullptr;
    char dest[] = "bbbb";
    int res = MemCopyByWordLen(dest, src, sizeof(dest));
    EXPECT_EQ(res, -1);

    char src2[] = "aaaa";
    char* dest2 = nullptr;
    int res2 = MemCopyByWordLen(dest2, src2, sizeof(src2));
    EXPECT_EQ(res2, -1);

    char src3[] = "bbbb";
    char* dest3 = src3;
    int res3 = MemCopyByWordLen(dest3, src3, sizeof(src3));
    EXPECT_EQ(res3, 0);
}

