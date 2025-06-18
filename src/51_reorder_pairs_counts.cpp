//
// Created by Damon on 2025/6/12.
//

#include "my_algorithms.h"

int GetReorderCntHelper(vector<int>& arr, vector<int>& temp, int left, int right)
{
    if (left >= right) {
        return 0;
    }
    int mid = left + ((right - left) >> 1);
    // 二分后，左右两边的数组分别的乱序对个数
    int reorderCnt = GetReorderCntHelper(arr, temp, left, mid) + GetReorderCntHelper(arr, temp, mid + 1, right);
    // 合并过程中，两个数组之间的乱序个数
    int leftIndex = left;
    int rightIndex = mid + 1;
    int tempIndex = left;
    while (leftIndex <= mid && rightIndex <= right) {
        if (arr[leftIndex] > arr[rightIndex]) {
            reorderCnt += (mid - leftIndex + 1);
            temp[tempIndex++] = arr[rightIndex++];
        } else {
            temp[tempIndex++] = arr[leftIndex++];
        }
    }
    while (leftIndex <= mid) {
        temp[tempIndex++] = arr[leftIndex++];
    }
    while (rightIndex <= right) {
        temp[tempIndex++] = arr[rightIndex++];
    }
    int copyIndex = left;
    for (int copyIndex = left; copyIndex <= right; copyIndex++) {
        arr[copyIndex] = temp[copyIndex];
    }
    return reorderCnt;
}

int GetReorderPairCnt(vector<int> arr)
{
    if (arr.size() < 1) {
        return 0;
    }

    vector<int> temp(arr.size());
    return GetReorderCntHelper(arr, temp, 0, arr.size() - 1);
}
