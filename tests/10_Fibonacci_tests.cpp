//
// Created by Damon on 2025/3/19.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

TEST(FibonacciTest, FibonacciTest)
{
    EXPECT_EQ(0, Fibonacci(0));
    EXPECT_EQ(1, Fibonacci(1));
    EXPECT_EQ(5, Fibonacci(5));
    EXPECT_EQ(8, Fibonacci(6));
    EXPECT_EQ(13, Fibonacci(7));
    EXPECT_EQ(21, Fibonacci(8));
    EXPECT_EQ(55, Fibonacci(10));
    EXPECT_EQ(89, Fibonacci(11));
    EXPECT_EQ(144, Fibonacci(12));
    EXPECT_EQ(233, Fibonacci(13));

    EXPECT_EQ(0, FibonacciByVec(0));
    EXPECT_EQ(1, FibonacciByVec(1));
    EXPECT_EQ(5, FibonacciByVec(5));
    EXPECT_EQ(8, FibonacciByVec(6));
    EXPECT_EQ(13, FibonacciByVec(7));
    EXPECT_EQ(21, FibonacciByVec(8));
    EXPECT_EQ(55, FibonacciByVec(10));
    EXPECT_EQ(89, FibonacciByVec(11));
    EXPECT_EQ(144, FibonacciByVec(12));
    EXPECT_EQ(233, FibonacciByVec(13));
   // EXPECT_EQ(233, Fibonacci(50));    运行时间居然有80s，我还以为我电脑卡了  ||  使用vector的形式只有5ms就运行完了
   // EXPECT_EQ(233, Fibonacci(30));    12ms
   // EXPECT_EQ(233, Fibonacci(40));    697ms
   // EXPECT_EQ(233, Fibonacci(45));     7s
}
