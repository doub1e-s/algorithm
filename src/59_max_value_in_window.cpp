//
// Created by Damon on 2025/6/18.
//

#include "my_algorithms.h"
#include <queue>
#include <algorithm>


// 核心思路是使用一个双端队列维护最大的index队列，index队列单调递增，新的元素来了之后，将队尾小于新元素的数据剔除
// 在新元素入队之前，也从队头开始，将所有过期的元素丢弃
vector<int> MaxValueInWindow(vector<int> nums, int window) {
    vector<int> result;
    if (window == 0) {
        return result;
    }
    if (window > nums.size()) {
        auto maxIt = max_element(nums.begin(), nums.end());
        result.push_back(*maxIt);
        return result;
    }
    deque<int> maxElementDeque;
    for (int i = 0; i < nums.size(); i++) {
        // 1. 删除过期数据  window = 3, i = 3, front = 0, 需要弹出一个元素;
        if (!maxElementDeque.empty() && ((i - maxElementDeque.front() + 1) > window)) {
            maxElementDeque.pop_front();
        }
        // 2. 从队尾插入元素，如果队尾小于当前值，则将其弹出
        while (!maxElementDeque.empty() && nums[maxElementDeque.back()] <= nums[i]) {
            maxElementDeque.pop_back();
        }
        // 3. 准备工作已做好，将当前的数组下标推入双端队列
        maxElementDeque.push_back(i);
        if (i >= window - 1) {
            result.push_back(nums[maxElementDeque.front()]);
        }
    }
    return result;
}

