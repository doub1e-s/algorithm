//
// Created by Damon on 2025/6/21.
//

#include "my_algorithms.h"

int Partition(vector<int>& vec, int left, int right)
{
    int small = left;
    int big = right - 1;
    while (small < big) {
        while (small < big && vec[small] <= vec[right]) {
            small++;
        }
        while (small < big && vec[big] >= vec[right]) {
            big--;
        }
        swap(vec[small], vec[big]);
    }
    // 左侧全部都是小于right的情况，直接返回当前的index
    if (small == right - 1 && vec[small] <= vec[right]) {
        return right;
    }
    // else small和big相当，或者right是
    swap(vec[right], vec[big]);
    return big;
}

void QuickSort(vector<int>& vec, int left, int right)
{
    if (vec.empty() || left < 0 || right >= vec.size() || left >= right) {
        return ;
    }
    // 1. 直接选择数组中最后一个数字，以这个数字为参考对象， 小于的放在左边，大于的放在右边
    int index = Partition(vec, left, right);   
    // 2. 分别递归执行左边剩余数字和右边剩余数字
    QuickSort(vec, left, index - 1);
    QuickSort(vec, index + 1, right);
}
