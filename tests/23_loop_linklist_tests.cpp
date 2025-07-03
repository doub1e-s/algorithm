//
// Created by Damon on 25-5-11.
//

#include <my_algorithms.h>
#include <gtest/gtest.h>

TEST(LoopLinkListTests, NormalTests)
{
    ListNode node5 = ListNode(5);
    ListNode node4 = ListNode(&node5, 4);
    ListNode node3 = ListNode(&node4, 3);
    ListNode node2 = ListNode(&node3, 2);
    ListNode node1 = ListNode(&node2, 1);
    node5.next = &node4;
    ListNode* res = GetLoopLinkListEntryNode(&node1);
    EXPECT_EQ(res, &node4);


    node5.next = &node3;
    res = GetLoopLinkListEntryNode(&node1);
    EXPECT_EQ(res, &node3);

    node5.next = &node2;
    res = GetLoopLinkListEntryNode(&node1);
    EXPECT_EQ(res, &node2);
}