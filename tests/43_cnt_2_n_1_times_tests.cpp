//
// Created by Damon on 2025/5/27.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(CountDigitOneTest, BasicTest) {
    EXPECT_EQ(CountToN1Times(13), 6);  // 1,10,11,12,13 → 6
    EXPECT_EQ(CountToN1Times(0), 0);   // 无数字
    EXPECT_EQ(CountToN1Times(1), 1);   // 1 → 1
    EXPECT_EQ(CountToN1Times(10), 2);  // 1,10 → 2
    EXPECT_EQ(CountToN1Times(1234), 689); // 更大的数
}

TEST(CountDigitOneTest, EdgeCases) {
    EXPECT_EQ(CountToN1Times(99), 20);  // 1-9,10-19,20-29,...,90-99 → 20
    EXPECT_EQ(CountToN1Times(100), 21); // 1-99 + 100 → 21
    EXPECT_EQ(CountToN1Times(101), 23); // 1-99 + 100 + 101 → 23


}