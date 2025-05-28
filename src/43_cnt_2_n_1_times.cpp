//
// Created by Damon on 2025/5/27.
//

#include "my_algorithms.h"

int CountToN1Times(int n)
{
    int count = 0; // 初始化计数器
    for (long long i = 1; i <= n; i *= 10) { // 遍历每一位（个位、十位、百位...）
        long long divider = i * 10; // 当前位的权重（如个位是10，十位是100）
        // 分别计算当前位的高位部分、当前位数字、低位部分
        int high = n / divider;      // 高位部分（当前位左边的数字）
        int current = (n / i) % 10;  // 当前位的数字
        int low = n % i;             // 低位部分（当前位右边的数字）

        if (current > 1) {
            // 当前位数字大于1时，高位部分+1后乘以权重
            count += (high + 1) * i;
        } else if (current == 1) {
            // 当前位数字等于1时，高位部分乘以权重 + 低位部分 + 1
            count += high * i + low + 1;
        } else {
            // 当前位数字小于1时，高位部分直接乘以权重
            count += high * i;
        }
    }
    return count;
}
