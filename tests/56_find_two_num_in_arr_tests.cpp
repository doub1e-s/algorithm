//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(FindTwoNumInArrTest, NormalTest)
{
    vector<int> vec = {1,1,2,2,3,4,4,5,5,6,6,7};
    pair<int, int> res = FindTwoNumInVec(vec);
    set<int> expectSet = {3, 7};
    set<int> actualSet;
    actualSet.insert(res.first);
    actualSet.insert(res.second);
    EXPECT_EQ(actualSet, expectSet);

    vector<int> vec2 = {1,2,1,3,4,4,5,5,6,2,6,7};
    pair<int, int> res2 = FindTwoNumInVec(vec2);
    set<int> expectSet2 = {3, 7};
    set<int> actualSet2;
    actualSet2.insert(res2.first);
    actualSet2.insert(res2.second);
    EXPECT_EQ(actualSet2, expectSet2);
}


