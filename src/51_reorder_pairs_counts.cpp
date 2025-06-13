//
// Created by Damon on 2025/6/12.
//

#include "my_algorithms.h"

int GetReorderCntHelper(vector<int>& arr, vector<int>& temp, int left, int right)
{
    if (left >= right) { return 0; }
    int mid = right + ((left - right) >> 1);
    int result = GetReorderCntHelper(arr, temp, left, mid) + GetReorderCntHelper(arr, temp, mid + 1, right);
    int arrLeftIdx = left;
    int arrRightIdx = mid + 1;
    int tempIdx = left;
    while (arrLeftIdx <= mid && arrRightIdx <= right) {
        if (arr[arrLeftIdx] <= arr[arrRightIdx]) {
            temp[tempIdx++] = arr[arrLeftIdx++];
        } else {
            temp[tempIdx++] = arr[arrRightIdx++];
            result += mid - arrLeftIdx + 1;
        }
    }
    while (arrLeftIdx <= mid) { temp[tempIdx++] = arr[arrLeftIdx++]; }
    while (arrRightIdx <= right) { temp[tempIdx++] = arr[arrRightIdx++]; }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return result;
}

int GetReorderPairCnt(vector<int> arr)
{
    if (arr.size() < 1) {
        return 0;
    }
    vector<int> temp(arr.size());
    return GetReorderCntHelper(arr, temp, 0, arr.size() - 1);
}
