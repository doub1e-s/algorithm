//
// Created by Damon on 2025/6/21.
//

#include "my_algorithms.h"

int Partition(vector<int>& vec, int left, int right)
{
    if (vec.empty() || left >= right) { return left; }
    int pivot = right;
    while (left < right) {
        while (left < right && vec[left] <= vec[pivot]) {
            left++;
        }
        while (left < right && vec[right] >= vec[pivot]) {
            right--;
        }
        swap(vec[left], vec[right]);
    }
    if (vec[right] > vec[pivot]) {
        swap(vec[left], vec[pivot]);
    }
    return left;
}

void QuickSort(vector<int>& vec, int left, int right)
{
    // 如果vec为空，或者left/right超过边界，直接返回
    if (vec.empty() || left < 0 || right >= vec.size() || left >= right) { return ; }
    // 找一个数字，将数组中的所有大于他的都放左边，小于他的都放右边
    int index = Partition(vec, left, right);
    // 返回这个数字的下标，递归执行他的左侧和右侧数组
    QuickSort(vec, left, index - 1);
    QuickSort(vec, index + 1, right);
}
