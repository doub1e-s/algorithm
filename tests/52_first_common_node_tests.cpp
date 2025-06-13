//
// Created by Damon on 2025/6/11.
//

#include "my_algorithms.h"
#include "utils/test_helper.h"
#include <gtest/gtest.h>

// 测试用例
TEST(IntersectionNodeTest, NormalCase) {
    // 链表A: 1 -> 2 -> 3 -> 6 -> 7
    // 链表B: 4 -> 5 -> 6 -> 7
    // 公共节点: 6
    ListNode* common = damon::createList({6, 7});
    ListNode* headA = damon::createList({1, 2, 3});
    ListNode* headB = damon::createList({4, 5});
    damon::connectLists(headA, headB, common);

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
    ListNode* headA = damon::createList({1, 2, 3});
    ListNode* headB = damon::createList({4, 5, 6});

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
    ListNode* headB = damon::createList({1, 2, 3});

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
    ListNode* common = damon::createList({1, 2, 3});
    ListNode* headA = common;
    ListNode* headB = common;

    ListNode* result = FindFirstCommonNode(headA, headB);
    EXPECT_EQ(result->value, 1);

    // 清理内存
    delete common->next->next; // 删除 3
    delete common->next;       // 删除 2
    delete common;             // 删除 1
}
