//
// Created by Damon on 2025/6/21.
//

#include "my_algorithms.h"

int Partition(vector<int>& vec, int left, int right)
{
    if (left == right) { return left; }
    int pivot = right;
    while (left < right) {
        while (left < right && vec[left] < vec[pivot]) {
            left++;
        }
        while (left < right && vec[right] >= vec[pivot]) {
            right--;
        }
        swap(vec[left], vec[right]);
    }
    if (vec[left] > vec[pivot]) {
        swap(vec[left], vec[pivot]);
    }
    return left;
}

void QuickSort(vector<int>& vec, int left, int right)
{
    if (vec.empty() || left < 0 || left > right || right >= vec.size()) {
        return ;
    }
    int partition = Partition(vec, left, right);
    QuickSort(vec, left, partition - 1);
    QuickSort(vec, partition + 1, right);
}
