//
// Created by Damon on 2025/5/16.
//

#include "my_algorithms.h"

TreeNode* MirrorTreeNode(TreeNode* head)
{
    if (!head) { return nullptr; }
    TreeNode* tempRight = head->right;
    TreeNode* tempLeft = head->left;
    head->left = MirrorTreeNode(tempRight); // 使用临时指针，确保不会使用成赋值后的值
    head->right = MirrorTreeNode(tempLeft);
    return head;
}