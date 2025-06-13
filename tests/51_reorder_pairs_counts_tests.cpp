//
// Created by Damon on 2025/6/12.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

// TEST用例
TEST(GetReorderPairCntTest, NormalCase) {
    std::vector<int> nums = {7, 5, 6, 4};
    EXPECT_EQ(GetReorderPairCnt(nums), 5);
}

TEST(GetReorderPairCntTest, AlreadySorted) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    EXPECT_EQ(GetReorderPairCnt(nums), 0);
}

TEST(GetReorderPairCntTest, ReverseSorted) {
    std::vector<int> nums = {5, 4, 3, 2, 1};
    EXPECT_EQ(GetReorderPairCnt(nums), 10);  // 4+3+2+1=10
}

TEST(GetReorderPairCntTest, EmptyArray) {
    std::vector<int> nums = {};
    EXPECT_EQ(GetReorderPairCnt(nums), 0);
}

TEST(GetReorderPairCntTest, SingleElement) {
    std::vector<int> nums = {1};
    EXPECT_EQ(GetReorderPairCnt(nums), 0);
}

TEST(GetReorderPairCntTest, TwoElementsAscending) {
    std::vector<int> nums = {1, 2};
    EXPECT_EQ(GetReorderPairCnt(nums), 0);
}

TEST(GetReorderPairCntTest, TwoElementsDescending) {
    std::vector<int> nums = {2, 1};
    EXPECT_EQ(GetReorderPairCnt(nums), 1);
}

TEST(GetReorderPairCntTest, ComplexCase) {
    std::vector<int> nums = {1, 2, 6, 7, 2, 6, 9, 4, 3};
    EXPECT_EQ(GetReorderPairCnt(nums), 12);
}

TEST(GetReorderPairCntTest, AllSameElements) {
    std::vector<int> nums = {3, 3, 3, 3};
    EXPECT_EQ(GetReorderPairCnt(nums), 0);
}

TEST(GetReorderPairCntTest, LargeArray) {
    std::vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    EXPECT_EQ(GetReorderPairCnt(nums), 45);  // 9+8+...+1=45
}