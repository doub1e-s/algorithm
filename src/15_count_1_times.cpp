//
// Created by Damon on 2025/4/10.
//

#include "my_algorithms.h"

int Count1Times(int value)
{
    int count1Times = 0;
    while (value != 0) {
        count1Times++;
        value = value & (value - 1);
    }
    return count1Times;
}
