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
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;
    head = node1;
    DeleteListNode(&head, &node2);
    EXPECT_EQ((head->next), node3);
    EXPECT_EQ(node2, nullptr);
}

TEST(DeleteNodeTest, DeleteHeadNode) {
    // 创建链表: 1 -> 2 -> 3
    ListNode* head;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    head = node1;
    DeleteListNode(&head, &node1);
    EXPECT_EQ((head->next), node3);
    EXPECT_EQ(head, node2);
}

TEST(DeleteNodeTest, DeleteTailNode) {
    // 创建链表: 1 -> 2 -> 3
    ListNode* head;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    head = node1;
    DeleteListNode(&head, &node3);
    EXPECT_EQ((node2->next), nullptr);
    EXPECT_EQ(node3, nullptr);
}