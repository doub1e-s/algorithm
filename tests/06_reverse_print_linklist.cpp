//
// Created by Damon on 2025/3/18.
//

#include <gtest/gtest.h>
#include "my_algorithms.h"

std::vector<int> TraverseListFromEnd(const ListNode* head);

TEST(TraverseListFromEnd, EmptyListTest)
{
    const ListNode* head = nullptr;
    std::vector<int> result = TraverseListFromEnd(head);
    std::vector<int> expected;
    EXPECT_EQ(result, expected);

    // 栈写法的测试
    result.clear();
    TraverseListFromEnd(head, result);
    EXPECT_EQ(result, expected);
}

TEST(TraverseListFromEnd, NormalTest)
{
    ListNode tail{nullptr, 1};
    ListNode three{&tail, 2};
    ListNode two{&three, 3};
    ListNode head{&two, 4};
    std::vector<int> result = TraverseListFromEnd(&head);
    std::vector<int> expected {1, 2, 3, 4};
    EXPECT_EQ(result, expected);

    result.clear();
    TraverseListFromEnd(&head, result);
    EXPECT_EQ(result, expected);
}

TEST(TraverseListFromEnd, SameTest)
{
    ListNode tail{nullptr, 1};
    ListNode three{&tail, 1};
    ListNode two{&three, 1};
    ListNode head{&two, 1};
    std::vector<int> result = TraverseListFromEnd(&head);
    std::vector<int> expected {1, 1, 1, 1};
    EXPECT_EQ(result, expected);

    result.clear();
    TraverseListFromEnd(&head, result);
    EXPECT_EQ(result, expected);
}