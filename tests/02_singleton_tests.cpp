//
// Created by Damon on 2025/3/13.
//

#include <gtest/gtest.h>
#include <my_algorithms.h>

TEST(SingletonTest, EqualCheck) {
    MySingleton& my_singleton1 = MySingleton::GetInstance();
    MySingleton& my_singleton2 = MySingleton::GetInstance();
    EXPECT_EQ(&my_singleton1, &my_singleton2);
    EXPECT_EQ(my_singleton1, my_singleton2); // 该类中没有重载 op ==，导致编译器不知道如何比较这两个对象
}