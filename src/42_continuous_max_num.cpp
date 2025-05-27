//
// Created by Damon on 2025/5/27.
//

#include "my_algorithms.h"

int GetMaxContinuousNumber(vector<int> nums)
{
    int preSum = 0;
    int curMax = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        preSum = max(0, preSum);
        curMax = max(curMax, preSum + nums[i]);
        preSum += nums[i];
    }
    return curMax;
}
