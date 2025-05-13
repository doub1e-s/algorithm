#include "my_algorithms.h"

bool IsSameTree(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2) { return true; }
    if (!node1 || !node2) { return false;}
    if (node1->m_value != node2->m_value) { return false; }
    return IsSameTree(node1->m_pLeft, node2->m_pLeft) && IsSameTree(node1->m_pRight, node2->m_pRight);
}

bool IsSubTree(TreeNode* node1, TreeNode* node2)
{
    if (!node2) { return true; }
    if (!node1) { return false; }
    return IsSameTree(node1, node2) || IsSubTree(node1->m_pLeft, node2) || IsSubTree(node1->m_pRight, node2);
}
