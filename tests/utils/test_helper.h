//
// Created by Damon on 2025/5/25.
//

#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "my_algorithms.h"

namespace damon
{
// 设计目标是确认是否为同一个树，其中一个为空也直接返回false
bool IsSameTree(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2) { return true; }
    if (!node1 || !node2) { return false;}
    if (node1->value != node2->value) { return false; }
    return IsSameTree(node1->left, node2->left) && IsSameTree(node1->right, node2->right);
}
}


#endif //TEST_HELPER_H
