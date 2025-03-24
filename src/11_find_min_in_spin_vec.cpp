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
        mid = (right - left) / 2 + left;
        if (vec[mid] < vec[right]) {
            left = mid + 1;
        } else if (vec[mid] < vec[right]) {
            right = mid - 1;
        }
    }
    return vec[mid];
}
