//
// Created by Damon on 2025/5/17.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(MinStackTests, NormalTests)
{
    MinStack<int> myStack;
    myStack.Push(2);
    myStack.Push(4);
    myStack.Push(3);
    myStack.Push(2);
    myStack.Push(6);
    myStack.Push(1);
    EXPECT_EQ(myStack.MinValue(), 1);
    myStack.Pop();
    EXPECT_EQ(myStack.MinValue(), 2);
    myStack.Pop();
    myStack.Pop();
    EXPECT_EQ(myStack.MinValue(), 2);
}