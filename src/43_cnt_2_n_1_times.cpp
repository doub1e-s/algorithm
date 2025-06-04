//
// Created by Damon on 2025/5/27.
//

#include "my_algorithms.h"
#include <algorithm>

int CountToN1Times(int n)
{
    if (n < 1) {
        return 0;
    }
    string str = "";
    for (int i = 1; i <= n; i++) {
        str += to_string(i);
    }
    return std::count(str.begin(), str.end(), '1');
}