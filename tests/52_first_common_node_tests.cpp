//
// Created by Damon on 2025/6/11.
//

#include "my_algorithms.h"
#include <gtest/gtest.h>

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

// 测试用例
TEST(IntersectionNodeTest, NormalCase) {
    // 链表A: 1 -> 2 -> 3 -> 6 -> 7
    // 链表B: 4 -> 5 -> 6 -> 7
    // 公共节点: 6
    ListNode* common = createList({6, 7});
    ListNode* headA = createList({1, 2, 3});
    ListNode* headB = createList({4, 5});
    connectLists(headA, headB, common);

    // 假设 getIntersectionNode 是已实现的函数
    ListNode* result = FindFirstCommonNode(headA, headB);
    EXPECT_EQ(result->value, 6);

    // 清理内存（简化示例，实际需更严谨）
    delete common->next; // 删除 7
    delete common;       // 删除 6
    // 注意：headA 和 headB 的内存未完全释放（测试中可忽略）
}

TEST(IntersectionNodeTest, NoIntersection) {
    // 链表A: 1 -> 2 -> 3
    // 链表B: 4 -> 5 -> 6
    // 无公共节点
    ListNode* headA = createList({1, 2, 3});
    ListNode* headB = createList({4, 5, 6});

    ListNode* result = FindFirstCommonNode(headA, headB);
    EXPECT_EQ(result, nullptr);

    // 清理内存
    delete headA->next->next; // 删除 3
    delete headA->next;       // 删除 2
    delete headA;             // 删除 1
    delete headB->next->next; // 删除 6
    delete headB->next;       // 删除 5
    delete headB;             // 删除 4
}

TEST(IntersectionNodeTest, OneListEmpty) {
    // 链表A: 空
    // 链表B: 1 -> 2 -> 3
    // 无公共节点
    ListNode* headA = nullptr;
    ListNode* headB = createList({1, 2, 3});

    ListNode* result = FindFirstCommonNode(headA, headB);
    EXPECT_EQ(result, nullptr);

    // 清理内存
    delete headB->next->next; // 删除 3
    delete headB->next;       // 删除 2
    delete headB;             // 删除 1
}

TEST(IntersectionNodeTest, SameList) {
    // 链表A 和链表B 是同一个链表
    // 公共节点: 第一个节点 1
    ListNode* common = createList({1, 2, 3});
    ListNode* headA = common;
    ListNode* headB = common;

    ListNode* result = FindFirstCommonNode(headA, headB);
    EXPECT_EQ(result->value, 1);

    // 清理内存
    delete common->next->next; // 删除 3
    delete common->next;       // 删除 2
    delete common;             // 删除 1
}
