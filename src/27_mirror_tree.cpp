//
// Created by Damon on 2025/5/16.
//

#include "my_algorithms.h"

TreeNode* MirrorTreeNode(TreeNode* head)
{
    if (!head) { return nullptr; }
    TreeNode* tempRight = head->m_pRight;
    TreeNode* tempLeft = head->m_pLeft;
    head->m_pLeft = MirrorTreeNode(tempRight);
    head->m_pRight = MirrorTreeNode(tempLeft);
    return head;
}