//
// Created by Damon on 2025/4/10.
//

#include "my_algorithms.h"

int Count1Times(int value)
{
    int res = 0;
    while (value) {
        value = value & (value - 1);
        res++;
    }
    return res;
}
