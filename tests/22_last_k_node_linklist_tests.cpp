//
// Created by Damon on 25-5-11.
//

#include <my_algorithms.h>
#include <gtest/gtest.h>

TEST(LastKNode, LastKNodeTest)
{
    ListNode node7 = ListNode(7);
    ListNode node6 = ListNode(&node7, 6);
    ListNode node5 = ListNode(&node6, 5);
    ListNode node4 = ListNode(&node5, 4);
    ListNode node3 = ListNode(&node4, 3);
    ListNode node2 = ListNode(&node3, 2);
    ListNode head = ListNode(&node2, 1);
    ListNode* res = GetLastKNode(&head, 3);
    EXPECT_EQ(res, &node5);
    res = GetLastKNode(&head, 1);
    EXPECT_EQ(res, &node7);
}

TEST(LastKNode, RangeTest)
{
    ListNode* head = nullptr;
    ListNode* nullptrRes = GetLastKNode(head, 1);
    EXPECT_EQ(nullptrRes, nullptr);
    ListNode node7 = ListNode(7);
    ListNode* NegtiveRes = GetLastKNode(&node7, -1);
    EXPECT_EQ(NegtiveRes, nullptr);
}