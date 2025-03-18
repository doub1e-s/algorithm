//
// Created by Damon on 2025/3/18.
//
#include <my_algorithms.h>
#include <stack>

std::vector<int> TraverseListFromEnd(const ListNode* head)
{
    std::vector<int> result;
    std::stack<int> values;
    while (head) {
        values.push(head->value);
        head = head->m_pNext;
    }
    while (!values.empty()) {
        result.push_back(values.top());
        values.pop();
    }
    return result;
}