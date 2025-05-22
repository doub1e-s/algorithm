//
// Created by Damon on 2025/5/16.
//

#include "my_algorithms.h"

TreeNode* MirrorTreeNode(TreeNode* head)
{
    if (!head) { return nullptr; }
    TreeNode* tempRight = head->right;
    TreeNode* tempLeft = head->left;
    head->left = MirrorTreeNode(tempRight);
    head->right = MirrorTreeNode(tempLeft);
    return head;
}