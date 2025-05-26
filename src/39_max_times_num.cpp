//
// Created by Damon on 2025/5/26.
//

#include "my_algorithms.h"
#include <map>

int GetMaxCntNumber(vector<int> nums)
{
    map<int, int> num2Cnt;
    for (int i = 0; i < nums.size(); i++) {
        num2Cnt[nums[i]]++;
    }
    for (auto it = num2Cnt.begin(); it != num2Cnt.end(); it++) {
        if (it->second >= nums.size() / 2) {
            return it->first;
        }
    }
    return 0;
}
