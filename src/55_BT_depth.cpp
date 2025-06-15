//
// Created by Damon on 2025/6/15.
//

#include "my_algorithms.h"

void BTDepthHelper(TreeNode* root, int& curDepth, int& maxDepth)
{
    if (!root) { return ; }
    curDepth++;
    if (curDepth > maxDepth) {
        maxDepth = curDepth;
    }
    if (root->left) {
        BTDepthHelper(root->left, curDepth, maxDepth);
    }
    if (root->right) {
        BTDepthHelper(root->right, curDepth, maxDepth);
    }
    curDepth--;
}

int BTDepth(TreeNode* root)
{
    if (!root) { return 0; }
    int curDepth = 0;
    int maxDepth = 0;
    BTDepthHelper(root, curDepth, maxDepth);
    return maxDepth;
}

bool IsBalanceTree(TreeNode* root)
{
    if (!root) { return true; }
    int leftTreeDepth = 0;
    int rightTreeDepth = 0;
    leftTreeDepth = BTDepth(root->left);
    rightTreeDepth = BTDepth(root->right);
    if (std::abs(leftTreeDepth - rightTreeDepth) > 1) {
        return false;
    }
    return IsBalanceTree(root->left) && IsBalanceTree(root->right);
}
