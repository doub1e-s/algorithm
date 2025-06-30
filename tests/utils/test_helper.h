//
// Created by Damon on 2025/5/25.
//

#ifndef TEST_HELPER_H
#define TEST_HELPER_H

#include "my_algorithms.h"

namespace damon
{
// 设计目标是确认是否为同一个树，其中一个为空也直接返回false
bool IsSameTree(TreeNode* node1, TreeNode* node2);

// 辅助函数：通过数组创建链表
ListNode* createList(const std::vector<int>& values);

// 辅助函数：连接两个链表的公共部分
void connectLists(ListNode* headA, ListNode* headB, ListNode* commonHead);

}
#endif //TEST_HELPER_H
