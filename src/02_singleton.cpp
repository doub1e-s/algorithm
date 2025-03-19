//
// Created by Damon on 2025/3/9.
//
#include "my_algorithms.h"

// c++11之后，保证了静态局部变量的初始化顺序，从而保证了线程安全
MySingleton& MySingleton::GetInstance()
{
    static MySingleton INSTANCE; // 仅在只会初始化一次
    return INSTANCE;
}
