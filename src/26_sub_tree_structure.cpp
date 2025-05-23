#include "my_algorithms.h"

// 设计目标是确认是否为同一个树，其中一个为空也直接返回false
bool IsSameTree(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2) { return true; }
    if (!node1 || !node2) { return false;}
    if (node1->value != node2->value) { return false; }
    return IsSameTree(node1->left, node2->left) && IsSameTree(node1->right, node2->right);
}

// 设计目标是确认是否为子树,只要node2是空，就返回false，但是要优先判断node2
bool IsSubTree(TreeNode* node1, TreeNode* node2)
{
    // 处理node2为空的场景
    if (!node2) { return true; }
    if (!node1) { return false; }
    return IsSameTree(node1, node2) || IsSubTree(node1->left, node2) || IsSubTree(node1->right, node2);
}
