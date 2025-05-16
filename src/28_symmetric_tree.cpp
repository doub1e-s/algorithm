//
// Created by Damon on 2025/5/17.
//

#include "my_algorithms.h"

bool SymmertricTree(TreeNode* left, TreeNode* right)
{
    if (!left && !right) { return true; }
    if (!left || !right) { return false; }
    if (left->m_value != right->m_value) { return false; }
    return SymmertricTree(left->m_pLeft, right->m_pRight) && SymmertricTree(left->m_pRight, right->m_pLeft);
}

bool SymmertricTree(TreeNode* head)
{
    if (!head) { return false; }
    return SymmertricTree(head->m_pLeft, head->m_pRight);
}
