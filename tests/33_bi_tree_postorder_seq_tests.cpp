//
// Created by Damon on 2025/5/21.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

using namespace std;

TEST(BinarySearchTreePostOrderTest, Normal)
{
    vector<int> postOrder = {5, 7, 6, 9, 11, 10, 8};
    EXPECT_EQ(true, BinarySearchTreePostOrder(postOrder));
    postOrder = {7,4,6,5};
    EXPECT_EQ(false, BinarySearchTreePostOrder(postOrder));
    postOrder = {1, 3, 2, 6, 5};
    EXPECT_EQ(true, BinarySearchTreePostOrder(postOrder));
}