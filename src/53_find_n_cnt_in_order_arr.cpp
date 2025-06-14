//
// Created by Damon on 2025/6/14.
//

#include "my_algorithms.h"

int FindFirstNum(const vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int firstInd = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] == target) {
            firstInd = mid;
            right = mid - 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return firstInd;
}

int FindLastNum(const vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int lastInd = 0;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] == target) {
            lastInd = mid;
            left = mid + 1;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return lastInd;
}

int FindNumInOrderedArr(const vector<int>& arr, int target)
{
    if (arr.empty()) { return 0; }
    int firstIndex = FindFirstNum(arr, target);
    if (firstIndex == -1) {
        return 0;
    }
    int lastIndex = FindLastNum(arr, target);
    return lastIndex - firstIndex + 1;
}