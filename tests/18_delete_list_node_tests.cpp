//
// Created by Damon on 2025/4/15.
//

#include <gtest/gtest.h>

#include "my_algorithms.h"

TEST(DeleteListNodeTests, DeleteMidNode)
{
    ListNode* head;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = node4;
    node4->m_pNext = node5;
    node5->m_pNext = node6;
    node6->m_pNext = NULL;
    head = node1;
    DeleteListNode(&head, &node2);
    EXPECT_EQ((head->m_pNext), node3);
    EXPECT_EQ(node2, nullptr);
}

TEST(DeleteNodeTest, DeleteHeadNode) {
    // 创建链表: 1 -> 2 -> 3
    ListNode* head;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    head = node1;
    DeleteListNode(&head, &node1);
    EXPECT_EQ((head->m_pNext), node3);
    EXPECT_EQ(head, node2);
}

TEST(DeleteNodeTest, DeleteTailNode) {
    // 创建链表: 1 -> 2 -> 3
    ListNode* head;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    head = node1;
    DeleteListNode(&head, &node3);
    EXPECT_EQ((node2->m_pNext), nullptr);
    EXPECT_EQ(node3, nullptr);
}