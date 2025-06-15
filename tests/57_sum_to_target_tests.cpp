//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(SumToTargetTests, NormalTests)
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pair<int, int> res = SumToTarget(vec, 3);
    set<int> expetedSet { 1, 2 };
    set<int> actual = { res.first, res.second };
    ASSERT_EQ(expetedSet, actual);
}

TEST(FindContinueSumTests, NormalTests)
{
    // 测试 target = 9
    {
        std::vector<std::vector<int>> expected = {{2, 3, 4}, {4, 5}};
        EXPECT_EQ(FindContinuesSum(9), expected);
    }

    // 测试 target = 15
    {
        std::vector<std::vector<int>> expected = {{1, 2, 3, 4, 5}, {4, 5, 6}, {7, 8}};
        EXPECT_EQ(FindContinuesSum(15), expected);
    }
}

TEST(ContinuousSequenceTest, EdgeCases) {
    // 测试 target = 1（无解）
    {
        std::vector<std::vector<int>> expected = {};
        EXPECT_EQ(FindContinuesSum(1), expected);
    }

    // 测试 target = 2（无解）
    {
        std::vector<std::vector<int>> expected = {};
        EXPECT_EQ(FindContinuesSum(2), expected);
    }

    // 测试 target = 3（解为 {1, 2}）
    {
        std::vector<std::vector<int>> expected = {{1, 2}};
        EXPECT_EQ(FindContinuesSum(3), expected);
    }
}

TEST(ContinuousSequenceTest, LargerTarget) {
    // 测试 target = 100（示例解可能包括 {9, 10, ..., 16} 等）
    // 注意：此处预期结果需根据实际算法调整
    {
        std::vector<std::vector<int>> expected = {{9, 10, 11, 12, 13, 14, 15, 16}, {18, 19, 20, 21, 22}}; // 示例
        EXPECT_EQ(FindContinuesSum(100), expected);
    }
}
