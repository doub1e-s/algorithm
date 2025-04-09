//
// Created by Damon on 2025/4/10.
//

#include "my_algorithms.h"

// 使用二分法的思想，叠加递归解决问题。 注意exponent是0，负数，不能整除2的情况
double GetPower(int value, int exponent)
{
    if (value == 0 && exponent == 0) { return 0; }
    if (exponent == 0) { return 1; }
    bool flip = false;
    if (exponent < 0) {
        flip = true;
        exponent = -exponent;
    }
    if (exponent == 1) {
        return value;
    }

    bool multyAnotherOne = false;
    if (exponent %2 == 1) { multyAnotherOne = true; }
    int part1 = GetPower(value, exponent / 2);
    double result;
    if (multyAnotherOne) {
        result = part1 * part1 * value;
    } else {
        result = part1 * part1;
    }
    if (!flip) {
        return result;
    }
    return 1 / result;
}
