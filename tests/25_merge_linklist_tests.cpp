//
// Created by Damon on 2025/5/12.
//

#include <gtest/gtest.h>
#include <my_algorithms.h>
#include <vector>

TEST(MergeLinkList, NormalTest)
{
    ListNode* node5 = new ListNode(5);
    ListNode* node3 = new ListNode(3);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node4 = new ListNode(4);
    ListNode* node6 = new ListNode(6);
    node1->m_pNext = node3;
    node3->m_pNext = node5;
    node2->m_pNext = node4;
    node4->m_pNext = node6;
    ListNode* head = Merge(node1, node2);
    std::vector<int> myVec;
    while (head) {
        myVec.push_back(head->m_value);
        head = head->m_pNext;
    }
    std::vector<int> compareVec = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(myVec, compareVec);
}