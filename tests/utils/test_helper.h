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

    // 辅助函数：通过数组创建链表
    ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

    // 辅助函数：连接两个链表的公共部分
    void connectLists(ListNode* headA, ListNode* headB, ListNode* commonHead) {
    // 找到 headA 和 headB 的尾节点
    ListNode* tailA = headA;
    while (tailA->next != nullptr) tailA = tailA->next;
    ListNode* tailB = headB;
    while (tailB->next != nullptr) tailB = tailB->next;

    // 连接公共部分
    tailA->next = commonHead;
    tailB->next = commonHead;
}
}


#endif //TEST_HELPER_H
