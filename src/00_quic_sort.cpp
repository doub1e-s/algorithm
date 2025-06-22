//
// Created by Damon on 2025/6/21.
//

#include "my_algorithms.h"

int Partition(vector<int>& vec, int left, int right)
{
    if (left >= right) { return left; }
    int small = left;
    int big = right - 1;
    int pivot = vec[right];
    while (small < big) {
        while (small < big && vec[small] <= pivot) {
            small++;
        }
        while (small < big && vec[big] >= pivot) {
            big--;
        }
        swap(vec[small], vec[big]);
    }
    // 如果存在比vec[right]更大的值，将他和right调换位置
    if (vec[small] >= pivot) {
        swap(vec[right], vec[small]);
    }
    return small;
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
