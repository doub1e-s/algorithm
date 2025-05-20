//
// Created by Damon on 2025/5/20.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

using namespace std;

TEST(StackSequenceTests, NormalTest)
{
    vector<int> pushSeq = {1,2,3,4,5,6,7,8,9};
    vector<int> popSeq = {1,2,3,4,5,6,7,8,9};
    EXPECT_TRUE(IsStackSeqence(pushSeq, popSeq));
    popSeq = {9,8,7,6,5,4,3,2,1};
    EXPECT_TRUE(IsStackSeqence(pushSeq, popSeq));
    popSeq = {3,1,2,4,5,6,7,8,9};
    EXPECT_FALSE(IsStackSeqence(pushSeq, popSeq));
}