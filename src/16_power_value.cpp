//
// Created by Damon on 2025/4/10.
//

#include "my_algorithms.h"

// 使用二分法的思想，叠加递归解决问题。 注意exponent是0，负数，不能整除2的情况

double GetPowerHelper(int value, int exponent)
{
    if (abs(exponent) == 1) {
        return value;
    }
    // 能减少递归的次数就尽量的减少递归的次数，将一半的结果存储下来，然后直接使用
    double halfResult = GetPowerHelper(value, exponent / 2);
    if (exponent % 2 == 0) {
        return halfResult * halfResult;
    } else {
        return halfResult * halfResult * value;
    }
}

double GetPower(int value, int exponent)
{
    if (value == 0) {
        return 0;
    }
    if (exponent == 0) {
        return 1;
    }
    double res = GetPowerHelper(value, exponent);
    if (exponent < 0) {
        res = 1 / res;
    }
    if (value < 0 && exponent % 2 != 0) {
        res = -res;
    }
    return res;
}
