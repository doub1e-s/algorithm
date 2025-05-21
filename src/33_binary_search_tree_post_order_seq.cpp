//
// Created by Damon on 2025/5/21.
//


#include "my_algorithms.h"


bool BinarySearchTreePostOrder(std::vector<int> postOrder, int left, int right)
{
    if (left >= right) { return true; }
    int root = postOrder[right];
    int firstRightTreeIndex = -1;
    for (int i = left; i < right; i++) {
        if (postOrder[i] > root) {
            firstRightTreeIndex = i;
            break;
        }
    }
    if (firstRightTreeIndex == -1) {
        return BinarySearchTreePostOrder(postOrder, left, right - 1);
    }
    for (int i = firstRightTreeIndex + 1; i < right; i++) {
        if (postOrder[i] < root) {
            return false;
        }
    }
    return BinarySearchTreePostOrder(postOrder, left, firstRightTreeIndex - 1) &&
        BinarySearchTreePostOrder(postOrder, firstRightTreeIndex, right - 1);
}

bool BinarySearchTreePostOrder(std::vector<int> postOrder)
{
    if (postOrder.empty()) { return false; }
    return BinarySearchTreePostOrder(postOrder, 0, postOrder.size() - 1);
}