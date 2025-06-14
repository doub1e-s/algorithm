//
// Created by Damon on 2025/6/14.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(FindNumInOrderedArrTest, TargetExistsMultipleTimes) {
    std::vector<int> arr = {1, 2, 3, 3, 3, 4, 5};
    int target = 3;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 3);
}

TEST(FindNumInOrderedArrTest, TargetExistsOnce) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int target = 3;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 1);
}

TEST(FindNumInOrderedArrTest, TargetDoesNotExist) {
    std::vector<int> arr = {1, 2, 4, 5};
    int target = 3;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 0);
}

TEST(FindNumInOrderedArrTest, EmptyArray) {
    std::vector<int> arr = {};
    int target = 1;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 0);
}

TEST(FindNumInOrderedArrTest, AllElementsSameAsTarget) {
    std::vector<int> arr = {2, 2, 2, 2, 2};
    int target = 2;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 5);
}

TEST(FindNumInOrderedArrTest, TargetAtBegin) {
    std::vector<int> arr = {1, 1, 2, 3, 4, 5};
    int target = 1;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 2);
}

TEST(FindNumInOrderedArrTest, TargetAtEnd) {
    std::vector<int> arr = {1, 2, 3, 4, 5, 5};
    int target = 5;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 2);
}

TEST(FindNumInOrderedArrTest, SingleElementMatch) {
    std::vector<int> arr = {1};
    int target = 1;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 1);
}

TEST(FindNumInOrderedArrTest, SingleElementNoMatch) {
    std::vector<int> arr = {1};
    int target = 2;
    EXPECT_EQ(FindNumInOrderedArr(arr, target), 0);
}