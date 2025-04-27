//
// Created by Damon on 2025/4/17.
//

#include <functional>
#include <my_algorithms.h>

// 需要考虑扩展性，当前题目是让所有的奇数放到左边，所有的偶数放到右边
void AdjustArrayOrder(std::vector<int>& vec, Predict predict)
{
    int left = 0, right = vec.size() - 1;
    while (left < right) {
        // 左指针所有的奇数都跳过
        while (left < right && predict(vec[left])) {
            left++;
        }
        while (left < right && !predict(vec[right])) {
            right--;
        }
        if (left < right) {
            std::swap(vec[left], vec[right]);
        }
    }
}
