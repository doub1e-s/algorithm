//
// Created by Damon on 2025/6/30.
//

#include "test_helper.h"

namespace damon {

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

bool IsSameTree(TreeNode* node1, TreeNode* node2)
{
    if (!node1 && !node2) { return true; }
    if (!node1 || !node2) { return false;}
    if (node1->value != node2->value) { return false; }
    return IsSameTree(node1->left, node2->left) && IsSameTree(node1->right, node2->right);
}

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

int GetSeprateSum(int num) {
    // 尚未考虑负数的问题
    int ret = 0;
    while (num != 0) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

}



