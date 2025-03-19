//
// Created by Damon on 2025/3/19.
//

#include "my_algorithms.h"

int Fibonacci(int n)
{
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int FibonacciByVec(int n)
{
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    std::vector<int> vec(n + 1);
    vec[0] = 0;
    vec[1] = 1;
    for (int i = 2; i <= n; i++) {
        vec[i] = vec[i - 1] + vec[i - 2];
    }
    return vec[n];
}