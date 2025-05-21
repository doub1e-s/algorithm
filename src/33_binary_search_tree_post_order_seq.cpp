//
// Created by Damon on 2025/5/21.
//


#include "my_algorithms.h"


bool BinarySearchTreePostOrder(std::vector<int> postOrder, int left, int right)
{
    if (left >= right) { return true; } // 不用判断right的值是否为负，因为当存在left作为左边界
    int root = postOrder[right];
    int firstRightTreeIndex = -1;
    for (int i = left; i < right; i++) {
        if (postOrder[i] > root) {
            firstRightTreeIndex = i;
            break;
        }
    }
    if (firstRightTreeIndex == -1) {    // 如果只存在左子树，则直接执行左子树的判断
        return BinarySearchTreePostOrder(postOrder, left, right - 1);
    }
    for (int i = firstRightTreeIndex + 1; i < right; i++) { // 需要判断是否右子树的值都大于当前root
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