//
// Created by Damon on 2025/5/26.
//

#include "my_algorithms.h"
#include <algorithm>

vector<int> GetMinKNums(vector<int> nums, int k)
{
    std::sort(nums.begin(), nums.end());
    vector<int> res;
    // 可以优化
    for (int i = 0; i < k; i++) {
        res.push_back(nums[i]);
    }
    return res;
}
