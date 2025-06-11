//
// Created by Damon on 2025/6/11.
//

#include "my_algorithms.h"

bool IsUglyNum(int num)
{
    if (num < 0) {
        return false;
    }
    while (num % 2 == 0) {
        num = num / 2;
    }
    while (num % 3 == 0) {
        num = num / 3;
    }
    while (num % 5 == 0) {
        num = num / 5;
    }
    if (num == 1) {
        return true;
    } else {
        return false;
    }
}

int FindXthUglyNum(int n)
{
    if (n <= 0) {
        return -1;
    }
    vector<int> uglys(n, 0);
    // 使用三个指针，分别指向因子是2,3,5.这三个指针在丑数的数组中逐步向前推进，代表 (2x)(3y)(5z)，xyz从0开始(0的时候则说明没有对应乘数)
    // xyz从0-n，如果将组合的值从小到大排序，则可以得到所有的丑数队列
    uglys[0] = 1;
    int divisor2 = 0;
    int divisor3 = 0;
    int divisor5 = 0;
    for (int i = 1; i < uglys.size(); i++) {
        while (uglys[i] <= uglys[i - 1]) {
            int nextUgly = min(uglys[divisor2] * 2, min(uglys[divisor3] * 3, uglys[divisor5] * 5));
            uglys[i] = nextUgly;
            if (nextUgly == uglys[divisor2] * 2) {
                divisor2++;
                continue;
            }
            if (nextUgly == uglys[divisor3] * 3) {
                divisor3++;
                continue;
            }
            if (nextUgly == uglys[divisor5] * 5) { divisor5++; }
        }
    }
    return uglys[n - 1];
}