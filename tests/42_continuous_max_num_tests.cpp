//
// Created by Damon on 2025/5/27.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(ContinuousMaxNumTests, NormalTest)
{
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    int res = GetMaxContinuousNumber(num);
    EXPECT_EQ(res, 6);
}

TEST(MaxSubArrayTest, BasicTest) {
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(GetMaxContinuousNumber(nums1), 6);  // 最大子数组 [4,-1,2,1]

    vector<int> nums2 = {1};
    EXPECT_EQ(GetMaxContinuousNumber(nums2), 1);  // 单个元素

    vector<int> nums3 = {5, 4, -1, 7, 8};
    EXPECT_EQ(GetMaxContinuousNumber(nums3), 23); // 整个数组

    vector<int> nums4 = {-1, -2, -3, -4};
    EXPECT_EQ(GetMaxContinuousNumber(nums4), -1); // 全负数，取最大单个元素
}

TEST(MaxSubArrayTest, EdgeCases) {
    vector<int> nums1 = {0};
    EXPECT_EQ(GetMaxContinuousNumber(nums1), 0);  // 0

    vector<int> nums2 = {INT_MIN};  // 测试最小值
    EXPECT_EQ(GetMaxContinuousNumber(nums2), INT_MIN);

    vector<int> nums3 = {INT_MAX};  // 测试最大值
    EXPECT_EQ(GetMaxContinuousNumber(nums3), INT_MAX);
}
