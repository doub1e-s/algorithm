//
// Created by Damon on 2025/3/15.
//

#include "my_algorithms.h"
// 需要关注一下test里面的char* 和char[]，数组和指针之间的区别

void ReplaceBlank(std::string& src)
{
    for (auto it = src.begin(); it != src.end(); ++it) {
        if(*it == ' ') {
            src.replace(it, it+1, "%20");
        }
    }
}

