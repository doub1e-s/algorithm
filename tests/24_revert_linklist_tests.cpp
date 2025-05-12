//
// Created by Damon on 2025/5/12.
//

#include <gtest/gtest.h>
#include <my_algorithms.h>

TEST(RevertLinklistTests, NormalTest)
{
    ListNode node6 = ListNode(6);
    ListNode node5 = ListNode(&node6, 5);
    ListNode node4 = ListNode(&node5, 4);
    ListNode node3 = ListNode(&node4, 3);
    ListNode node2 = ListNode(&node3, 2);
    ListNode node1 = ListNode(&node2, 1);
    ListNode* res = RevertLinkList(&node1);
    EXPECT_EQ(res, &node6);
}