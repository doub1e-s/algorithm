//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"

void InorderTraverse(TreeNode* cur, vector<int>& res)
{
    if (!cur) { return ; }
    if (cur->right) {
        InorderTraverse(cur->right, res);
    }
    res.push_back(cur->value);
    if (cur->left) {
        InorderTraverse(cur->left, res);
    }
}

int FindLargeKNode(TreeNode* head, int k)
{
    if (!head || k <= 0) {
        return -1;
    }
    vector<int> inorderValue;
    InorderTraverse(head, inorderValue);
    if (k > inorderValue.size()) {
        return -1;
    }
    return inorderValue[k - 1];
}