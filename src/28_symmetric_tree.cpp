//
// Created by Damon on 2025/5/17.
//

#include "my_algorithms.h"

bool SymmertricTree(TreeNode* left, TreeNode* right)
{
    if (!left && !right) { return true; }
    if (!left || !right) { return false; }
    if (left->value != right->value) { return false; }
    return SymmertricTree(left->left, right->right) && SymmertricTree(left->right, right->left);
}

bool SymmertricTree(TreeNode* head)
{
    if (!head) { return false; }
    return SymmertricTree(head->left, head->right);
}
