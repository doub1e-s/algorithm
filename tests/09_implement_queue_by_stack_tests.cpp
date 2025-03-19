//
// Created by Damon on 2025/3/19.
//

#include <queue>


#include <gtest/gtest.h>
#include "my_algorithms.h"

TEST(MyStackTest, InsertTest)
{
    std::queue<int> compare;
    MyQueue myQueue;
    myQueue.Push(1);
    compare.push(1);
    myQueue.Push(2);
    compare.push(2);
    myQueue.Push(3);
    compare.push(3);
    std::vector<int> my;
    std::vector<int> comp;
    while (!comp.empty()) {
        my.push_back(myQueue.Top());
        myQueue.Pop();
        comp.push_back(compare.front());
        compare.pop();
    }
    EXPECT_EQ(my, comp);
}

TEST(MyStackTest, WithPop)
{
    std::queue<int> compare;
    MyQueue myQueue;
    myQueue.Push(1);
    compare.push(1);
    myQueue.Push(2);
    compare.push(2);
    myQueue.Pop();
    compare.pop();
    myQueue.Push(3);
    compare.push(3);
    std::vector<int> my;
    std::vector<int> comp;
    while (!comp.empty()) {
        my.push_back(myQueue.Top());
        myQueue.Pop();
        comp.push_back(compare.front());
        compare.pop();
    }
    EXPECT_EQ(my, comp);
}

TEST(MyStackTest, AllPop)
{
    std::queue<int> compare;
    MyQueue myQueue;
    myQueue.Push(1);
    compare.push(1);
    myQueue.Push(2);
    compare.push(2);
    myQueue.Pop();
    compare.pop();
    myQueue.Push(3);
    compare.push(3);
    myQueue.Pop();
    compare.pop();
    myQueue.Pop();
    compare.pop();
    std::vector<int> my;
    std::vector<int> comp;
    while (!comp.empty()) {
        my.push_back(myQueue.Top());
        myQueue.Pop();
        comp.push_back(compare.front());
        compare.pop();
    }
    EXPECT_EQ(my, comp);
}