//
// Created by Damon on 2025/3/24.
//

#include "my_algorithms.h"

int FindMinInSpinVec(std::vector<int>& vec)
{
    if (vec.empty()) { return -1; }
    int left = 0;
    int right = vec.size() - 1;
    int mid;
    while (left < right) {
        if (right - left == 1) { return vec[right]; }
        mid = (right - left) / 2 + left;
        // 不能使用mid和左右两边比较是否小，因为可能存在当前值是最大值的可能。
        // 理想状态应该是，最后状态是，左边指针是最大值，右边指针是最小值。
        if (vec[mid] >= vec[left]) {    // 这里一定要包含等于，可能出现3112 这样的序列，如此还是可能死循环
            left = mid;
        } else if (vec[mid] <= vec[right]) {
            right = mid;
        }
    }
    return vec[left];
}
