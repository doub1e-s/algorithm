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
        mid = left + (right - left) / 2;
        if (vec[mid] > vec[right]) {
            left = mid + 1;     // left 最终指向的是最小值
        } else if (vec[mid] < vec[right]) {
            right = mid;
        } else {
            right--;    // mid和right相同时， 说明突变点在左侧，让right--
        }
    }
    return vec[left];
}
