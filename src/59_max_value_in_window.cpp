//
// Created by Damon on 2025/6/18.
//

#include "my_algorithms.h"
#include <queue>


// 核心思路是使用一个双端队列维护最大的index队列，index队列单调递增，新的元素来了之后，将队尾小于新元素的数据剔除
// 在新元素入队之前，也从队头开始，将所有过期的元素丢弃
vector<int> MaxValueInWindow(vector<int> nums, int window) {
    vector<int> result; // 修正：用 vector 存储结果
    if (nums.empty() || window <= 0) return result; // 直接返回空 vector

    deque<int> maxIndexDq; // 存储索引（单调递减队列）

    for (int i = 0; i < nums.size(); ++i) {
        // 1. 移除过期索引（不在当前窗口内）
        if (!maxIndexDq.empty() && maxIndexDq.front() <= i - window) {
            maxIndexDq.pop_front();
        }

        // 2. 维护单调递减队列（从队尾移除比当前元素小的索引）
        while (!maxIndexDq.empty() && nums[maxIndexDq.back()] < nums[i]) {
            maxIndexDq.pop_back();
        }

        // 3. 当前索引入队
        maxIndexDq.push_back(i);

        // 4. 记录最大值（当窗口大小达到 window 时）
        if (i >= window - 1) {
            result.push_back(nums[maxIndexDq.front()]);
        }
    }

    return result; // 直接返回结果
}

